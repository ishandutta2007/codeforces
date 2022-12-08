#include <bits/stdc++.h>

using namespace std;

int a[5005], c[5005], v[5005][5005], dp[5005];
vector<int> p[5005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) p[i].clear(), p[i].push_back(0);
	for (int i = 0; i <= n + 1; ++i) {
		fill(v[i], v[i] + n + 5, 0);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		v[i - 1][i] = 1;
		for (int j = i; j < n; j += 2) {
			++c[a[j]], ++c[a[j + 1]];
			mx = max(mx, max(c[a[j]], c[a[j + 1]]));
			if (mx * 2 <= j - i + 2) v[i - 1][j + 2] = 1;
		}
		for (int j = i; j < n; j += 2) {
			--c[a[j]], --c[a[j + 1]];
		}
	}
	v[n][n + 1] = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		p[i].push_back(n + 1);
		fill(dp, dp + n + 5, -100000);
		dp[0] = 0;
		for (int j = 1; j < p[i].size(); ++j) {
			for (int k = 0; k < j; ++k) {
				if (v[p[i][k]][p[i][j]]) dp[j] = max(dp[j], dp[k] + 1);
			}
		}
		ans = max(ans, dp[p[i].size() - 1] - 1);
	}
	cout << ans << "\n";
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