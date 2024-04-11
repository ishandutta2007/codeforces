#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c; cin >> r >> c;
	vector<string> grid(r, "");
	for (int i = 0; i < r; ++i) {
		cin >> grid[i];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (grid[i][j] == 'W') {
				for (int mt = 0; mt < 4; ++mt) {
					int ni = i + dx[mt];
					int nj = j + dy[mt];
					if (0 <= ni && ni < r && 0 <= nj && nj < c && grid[ni][nj] == 'S') {
						cout << "No" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	vector<vector<char>> newgrid(r, vector<char>());
	for (int i = 0; i < r; ++i) {
		newgrid[i] = vector<char>(grid[i].begin(), grid[i].end());
		for (int j = 0; j < c; ++j) {
			if (newgrid[i][j] == '.') {
				newgrid[i][j] = 'D';
			}
			cout << newgrid[i][j];
		}
		cout << endl;
	}
	return 0;
}