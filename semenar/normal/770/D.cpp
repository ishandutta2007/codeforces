#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int tmp;
	cin >> tmp;
	string par;
	cin >> par;
	int balance = 0;
	int max_balance = 0;
	int width = 0;
	for (int i = 0; i < par.size(); i++) {
		if (par[i] == '[') balance++;
		else balance--;

		if (balance > max_balance) max_balance = balance;

		width++;
		if (par[i] == ']' && par[i - 1] == '[') width += 3;
	}
	vector<string> board(2 * max_balance + 1, string(width, ' '));
	width = 0;
	balance = 0;
	for (int i = 0; i < par.size(); i++) {
		if (par[i] == '[') {
			board[balance][width] = '+';
			board[2 * max_balance - balance][width] = '+';
			board[balance][width + 1] = '-';
			board[2 * max_balance - balance][width + 1] = '-';
			for (int j = balance + 1; j < 2 * max_balance - balance; j++) board[j][width] = '|';
			width++;
			balance++;
		}
		if (par[i] == ']') {
			balance--;
			if (par[i - 1] == '[') width += 3;
			board[balance][width] = '+';
			board[2 * max_balance - balance][width] = '+';
			board[balance][width - 1] = '-';
			board[2 * max_balance - balance][width - 1] = '-';
			for (int j = balance + 1; j < 2 * max_balance - balance; j++) board[j][width] = '|';
			width++;
		}


	}
	for (int i = 0; i < board.size(); i++) cout << board[i] << endl;
	return 0;
}