#include <bits/stdc++.h>

using namespace std;

void solve() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	int l = 1, r = 1e9, ans;
	while (l <= r) {
		vector<int> vis(m);
		int mid = (l + r) >> 1;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			bool tmp = false;
			for (int j = 0; j < m; ++j) {
				if (a[j][i] >= mid) {
					++vis[j];
					tmp = true;
				}
			}
			if (!tmp) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			r = mid - 1;
			continue;
		}
		ok = false;
		for (int j = 0; j < m; ++j) {
			if (vis[j] > 1) {
				ok = true;
				break;
			}
		}
		if (ok) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << '\n';
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