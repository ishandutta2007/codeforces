#include <bits/stdc++.h>

using namespace std;
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
string mp[100];
int a[100][100];

void solve() {
	memset(a, 0, sizeof a);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'B') {
				a[i + 1][j + 1] = a[i][j + 1] = a[i + 2][j + 1] = a[i + 1][j] = a[i + 1][j + 2] = -1;
			}
			if (mp[i][j] == '#') {
				a[i + 1][j + 1] = -1;
			}
		}
	}
	if (a[n][m] != -1) {
		queue<pair<int, int>> q;
		q.emplace(n, m);
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (auto i: dir) {
				int x = p.first + i[0], y = p.second + i[1];
				if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0) {
					a[x][y] = 1;
					q.emplace(x, y);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'G' && a[i + 1][j + 1] != 1) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}