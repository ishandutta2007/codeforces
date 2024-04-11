#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int x, y, s = -2e9;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > s) {
				x = i;
				y = j;
				s = a[i][j];
			}
		}
	}
//	cout << x << ' ' << y << '\n';
	int dx = max(x + 1, n - x), dy = max(y + 1, m - y);
	cout << dx * dy << '\n';
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