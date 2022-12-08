#include <bits/stdc++.h>

using namespace std;

long long a[200][200];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	long long ans = 0;
	for (int l = 1, r = m; l <= r; ++l, --r) {
		for (int u = 1, d = n; u <= d; ++u, --d) {
			vector<long long> v;
			v.push_back(a[u][l]);
			v.push_back(a[u][r]);
			v.push_back(a[d][l]);
			v.push_back(a[d][r]);
			sort(v.begin(), v.end());
			long long avg = v[1], ans1 = 0;
			ans1 += abs(a[u][l] - avg);
			if (l != r) ans1 += abs(a[u][r] - avg);
			if (u != d) {
				ans1 += abs(a[d][l] - avg);
				if (l != r) ans1 += abs(a[d][r] - avg);
			}
			ans += ans1;
		}
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}