#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int R, C;
	cin >> R >> C;
	char grid[R][C];
	bool ok = true;
	string line;
	for (int i = 0; i < R; i++) {
		cin >> line;
		for (int j = 0; j < C; j++) {
			grid[i][j] = line[j];
			if (line[j] == '.') grid[i][j] = 'D';
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] != 'S') continue;
			if (i > 0 && grid[i-1][j] == 'W') ok = false;
			if (j > 0 && grid[i][j-1] == 'W') ok = false;
			if (i < R-1 && grid[i+1][j] == 'W') ok = false;
			if (j < C-1 && grid[i][j+1] == 'W') ok = false;
		}
	}
	if (!ok) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
	cin >> R;
}