#include <bits/stdc++.h>

using namespace std;

string s[100];

void solve() {
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	--x, --y;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	if (s[x][y] == 'B') {
		cout << 0 << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i][y] == 'B') {
			cout << 1 << '\n';
			return;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (s[x][i] == 'B') {
			cout << 1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'B') {
				cout << 2 << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
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