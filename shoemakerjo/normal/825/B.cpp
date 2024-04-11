#include <bits/stdc++.h>

using namespace std;

int main() {
	bool poss = false;
	char grid[10][10];
	string line;
	for (int i = 0; i < 10; i++) {
		cin >> line;
		for (int j = 0; j < 10; j++) {
			grid[i][j] = line[j];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j]!='.') continue;
			grid[i][j] = 'X';
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 6; l++) {
					if (grid[k][l] == 'X' && grid[k][l+1] == 'X' && grid[k][l+2] == 'X' && 
						grid[k][l+3] == 'X' && grid[k][l+4] == 'X') {
						poss = true;
					}
				}
			}
			for (int k = 0; k < 6; k++) {
				for (int l = 0; l < 10; l++) {
					if (grid[k][l] == 'X' && grid[k+1][l] == 'X' && grid[k+2][l] =='X'
						&& grid[k+3][l] == 'X' && grid[k+4][l] == 'X') {
						poss = true;
					}
				}
			}
			for (int k = 0; k < 6; k++) {
				for (int l = 0; l < 6; l++) {
					if (grid[k][l] == 'X' && grid[k+1][l+1] == 'X' && grid[k+2][l+2] == 'X' && 
						grid[k+3][l+3] =='X' && grid[k+4][l+4] == 'X') {
						poss = true;
					}
				}
			}
			for (int k = 9; k >= 4; k--) {
				for (int l = 0; l < 6; l++) {
					if (grid[k][l] == 'X' && grid[k-1][l+1] == 'X' && grid[k-2][l+2] == 'X' && 
						grid[k-3][l+3] == 'X' && grid[k-4][l+4] == 'X') {
						poss = true;
					}
				}
			}
			grid[i][j] = '.';
		}
	}
	if (poss) cout << "YES\n";
	else cout << "NO\n";
	cin >> line;
}