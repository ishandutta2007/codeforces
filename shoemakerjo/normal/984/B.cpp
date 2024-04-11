#include <bits/stdc++.h>

using namespace std;

char grid[105][105];

int n, m;

int go (int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	if (grid[x][y] == '*') return 1;
	return 0;
}

int getct(int x, int y) {
	int ans = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0) continue;
			ans += go(x+i, y+j);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n, m;
	cin >> n >> m;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = line[j];
		}
	}
	bool ans = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c = grid[i][j];
			int val = c-'0';
			if (val >= 1 && val <= 8) {
				if (val != getct(i, j)) ans = false;
			}
			if (c == '.') if (getct(i, j) != 0) ans = false;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}