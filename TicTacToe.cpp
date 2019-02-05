/*///////////////////////////////////////////////////////
Assignment02 Part C: Tic Tac Toe
Written by: Thomas Sechrist and Stephanie Sechrist
Due Date: 10.19.18
Last Edited 10.10.18
This program uses four functions in addition to main to 
draw a board using a 2D [3][3] array. The user is asked
to enter the array position for a given player (X or O).
The program will tell the user if there is a win or a draw.
It displays the board before every user inquiry.
*////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// funtion prototypes provided
bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

// main provided
int main()
{
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true)
	{
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
				if (isWon('X', board)) {
					cout << "X player won" << endl;
					exit(0);
				}
				else if (isDraw(board)) {
					cout << "No winner" << endl;
					exit(0);
				}

				// The second player makes a move
				makeAMove(board, 'O');
				displayBoard(board);

				if (isWon('O', board)) {
					cout << "O player won" << endl;
					exit(0);
				}
				else if (isDraw(board)) {
					cout << "No winner" << endl;
					exit(0);
				}			
	}

	return 0;
}

// isWon checks the board to see if the given player has won.
// it checks for all win conditions.
// returns true if player has won.
// returns false if player has not won.
bool isWon(char player, char currBoard[][3])
{
	if (currBoard[1][1] == player)
	{
		// check down slope diagonal
		if (currBoard[0][0] == player && currBoard[2][2] == player)
			return true;
		// check up slope diagonal
		if (currBoard[0][2] == player && currBoard[2][0] == player)
			return true;
		// check middle column
		if (currBoard[0][1] == player && currBoard[2][1] == player)
			return true;
		// check middle row
		if (currBoard[1][0] == player && currBoard[1][2] == player)
			return true;
	}

	if (currBoard[0][0] == player)
	{
		// check left column
		if (currBoard[1][0] == player && currBoard[2][0] == player)
			return true;
		// check top row
		if (currBoard[0][1] == player && currBoard[0][2] == player)
			return true;
	}

	if (currBoard[2][2] == player)
	{
		// check bottom row
		if (currBoard[2][0] == player && currBoard[2][1] == player)
			return true;
		// check right column
		if (currBoard[0][2] == player && currBoard[1][2] == player)
			return true;
	}
	
	// no win condiitions satisfied
	return false;
}

// isDraw checks the board for a draw.
// a draw only occurs when all entries of 2D array are filled, so there
//	 are no more moves to make, and no one has won.
// none of win conditions from isWon were satisfied.
// returns true if all entries contain 'X' or 'O' and no one has won.
// returns false otherwise.
bool isDraw(char drawBoard[][3])
{
	bool xWon = (isWon('X', drawBoard));
	bool oWon = (isWon('O', drawBoard));

	if (!xWon && !oWon)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// if any entry empty, not a draw. can still play
				if (drawBoard[i][j] == ' ')
					return false;
			}
		}
		//if for loop completes, then grid is full and no one won
		return true;
	}

	else
		return false;
}

// displayBoard shows the board at moment of function call
void displayBoard(char showBoard[][3])
{
	cout << endl;
	cout << "-------------" << endl;

	// traverse 2D array
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << showBoard[i][j] << " ";
		}

		cout << "|" << endl;
		cout << "-------------" << endl;
	}
}

// makeAMove is called by main to add player symbol ('X' or 'O') 
//	 to array position chosen by the user.
// also responsible for user interface.
// checks to make sure user is not trying to enter anything other
//	than 0,1,2 and that user is not trying to enter into occupied
//	entry.
void makeAMove(char moveBoard[][3], char player)
{
	int row;
	int column;

	cout << "Enter a row (0, 1, 2) for player " << player;
	cout << "   : ";
	cin >> row;

	// user input check
	if (row > 2)
	{
		cout << "Invalid entry." << endl;
		cout << "Enter a row (0, 1, 2) for player " << player;
		cout << "   : ";
		cin >> row;
	}

	// user input check.
	cout << "Enter a column (0, 1, 2) for player " << player;
	cout << ": ";
	cin >> column;

	if (column > 2)
	{
		cout << "Invalid entry." << endl;
		cout << "Enter a column (0, 1, 2) for player " << player;
		cout << "   : ";
		cin >> column;
	}

	// won't add to position if already occupied.
	if (moveBoard[row][column] != ' ')
	{
		cout << "This cell is already occupied. Try a different cell." << endl;
		makeAMove(moveBoard, player);
	} 

	else
	{
		moveBoard[row][column] = player;
	} 
}