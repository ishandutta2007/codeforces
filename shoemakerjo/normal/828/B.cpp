#include <bits/stdc++.h>

using namespace std;

int main() {
	int bot = -1, top = -1, right = -1, left = -1;
	int n, m;
	cin >> n >> m;
	string line;
	bool black[n][m];
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			if (line[j] == 'W') black[i][j] = false;
			else {
				if (top == -1) {
					top = i;
					bot = i;
					left = j;
					right = j;
				}
				top = min(top, i);
				bot = max(bot, i);
				left = min(left, j);
				right = max(right, j);
				black[i][j] = true;
			}
		}
	}
	int ans = 0;
	if (bot == -1) cout << 1 << endl;
	else {
		for (int i = top; i <= bot; i++) {
			for (int j = left; j <= right; j++) {
				if (!black[i][j]) ans++;
			}
		}
		int rows = bot-top+1;
		int cols = right-left+1;
		if (rows != cols) {
			if (cols > rows) {
				if (cols > n) cout << -1 << endl;
				else cout << cols*(cols-rows)+ans << endl;
			}
			else {
				if (rows > m) cout << -1 << endl;
				else cout << rows*(rows-cols)+ans << endl;
			}
		}
		else cout << ans << endl;
	}
	cin >> n;
}