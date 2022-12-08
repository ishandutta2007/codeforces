#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	int s = n + m - 1;
	if (s & 1) {
		cout << "NO\n";
		return;
	}
	vector<vector<bitset<1000>>> b(n, vector<bitset<1000>>(m));
	if (a[0][0] == 1) b[0][0][1] = 1;
	else b[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i < n - 1) {
				if (a[i + 1][j] == 1) b[i + 1][j] |= b[i][j] << 1;
				else b[i + 1][j] |= b[i][j];
			}
			if (j < m - 1) {
				if (a[i][j + 1] == 1) b[i][j + 1] |= b[i][j] << 1;
				else b[i][j + 1] |= b[i][j];
			}
		}
	}
	if (b[n - 1][m - 1][s / 2]) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}