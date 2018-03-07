//Saally Campos 
//17 November 2017
//Program 6

#include <iostream>
#include <string>
using namespace std; 

int Game(int goal, int turns, int token);
bool PlayAgain();

int main() {
	bool Playing = true;
	int game;

	//create loop to keep playing until user wants to stop
	while (Playing) {
		//get input
		int tokens, turns;
		cout << "Enter the number of tokens you want to reach: ";
		cin >> tokens;
		cout << "What is the number of turns: ";
		cin >> turns;
		cout << "Searching for a solution within " << turns << " turns...\n";
		
		//Calculate if goal can be found
		game = Game(tokens, turns, 13);

		//output results
		if (game > -1)
			cout << "Solution was found with " << game << " turns left" << endl;
		else
			cout << turns << " turns.\n";

		//check if user wants to play again.
		Playing = PlayAgain();
	}

	return 0;
}

int Game(int goal, int turn, int token)
{
	//If we're out of turns, return that it was not possible with x turns
	if (turn == 0) {
		cout << "Solution not found with ";
		return -1;
	}
	cout << "TURN: " << turn <<":  ";

	//if goal was found, return the current turn 
	if (token == goal) {
		cout << token << " == " << goal << "!!!\n";
		return turn;
	}

	//If adding 25 will give us the goal, add 25 & return current turn
	if (token + 25 == goal) {
		cout << token << "+25= ";
		token += 25;
		cout <<token<< "\n";
		return turn;
	}

	//If giving back half will give us the goal, divide by 2 & return current turn
	if (token / 2 == goal) {
		cout << token << "/2=  ";
		token /=2;
		cout << token << "\n";
		return turn;
	}

	//If tokens is even divide by 2
	if (token % 2 == 0) {
		cout << token << "/2=  ";
		token /= 2;
		cout << token << "\n";
	}

	//If we need to decrease tokens to reach goal, divide by 2
	else if (token > goal) {
		cout << token << "/2=  ";
		token /= 2;
		cout << token << "\n";
	}

	//if tokens are even or if we need to increase tokens to reach goal, add 25
	else if (token % 1 == 1 || token < goal) {
		cout << token << "+25= ";
		token += 25;
		cout << token << "\n";
	}

	//recursion with one less turn
	return Game(goal, turn - 1, token);

}

bool PlayAgain()
{
	bool valid = false;
	while (!valid) {
		cout << "\nWould you like to play again? \nEnter Y for yes or N for no:";
		string x;
		cin >> x;

		/*getline(cin, x);--> this doesnt work and it runs the else 
								statement every time PlayAgain is called
								for some reason??????*/
		if (x == "Y" || x == "y")
			return true;

		if (x == "N" || x == "n")
			return false;
		else
			cout << "Please enter a valid input.\n";
	}
}