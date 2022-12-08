#include <bits/stdc++.h>

using namespace std;

int main() {
	string grid[11];
	for (int i = 0; i < 11; i++) {
		getline(cin, grid[i]);
	}
	int x, y;
	cin >> x >> y;
	int xs, xe, ys, ye;
	int xm = (x-1)%3;
	int ym = (y-1)%3;
	if (xm == 0) {
		xs = 0;
		xe = 2;
	}
	if (xm == 1) {
		xs = 4;
		xe = 6;
	}
	if (xm == 2) {
		xs = 8;
		xe = 10;
	}
	if (ym == 0) {
		ys = 0;
		ye = 2;
	}
	if (ym == 1) {
		ys = 4;
		ye = 6;
	}
	if (ym == 2) {
		ys = 8;
		ye = 10;
	}
	int cur = 0;
	for (int i = xs; i <= xe; i++) {
		for (int j = ys; j <= ye; j++) {
			if (grid[i][j] == '.') {
				grid[i][j] = '!';
				cur++;
			}
		}
	}
	if (cur == 0) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < grid[i].length(); j++) {
				if (grid[i][j] == '.') {
					grid[i][j] = '!';
				}
			}
		}
	}
	for (int i = 0; i < 11; i++) {
		cout << grid[i] << endl;
	}
	cin >> x;

}