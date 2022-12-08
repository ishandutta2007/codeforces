#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	char grid[n][5];

	bool found = false;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
//		cout << grid[i] << endl;
//		cout << found;
		if (!found && grid[i][0] == 'O' && grid[i][1] == 'O') {
			found = true;
			grid[i][0] = '+';
			grid[i][1] = '+';
		}
		if (!found && grid[i][3] == 'O' && grid[i][4] == 'O') {
			found = true;
//			cout << "here";
			grid[i][3] = '+';
			grid[i][4] = '+';
		}

	}
	if (found) {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			cout << grid[i][0] << grid[i][1] << grid[i][2] << grid[i][3] << grid[i][4] << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}