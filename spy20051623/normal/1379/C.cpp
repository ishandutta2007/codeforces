#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<int, int> a[100005];
long long s[100005];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + m + 1, greater<pair<int, int>>());
	for (int i = 1; i <= m; ++i) {
		s[i] = s[i - 1] + a[i].first;
	}
	long long ans = 0;
	if (n <= m) ans = s[n];
	for (int i = 1; i <= m; ++i) {
		int p = lower_bound(a + 1, a + m + 1, make_pair(a[i].second, 0), greater<pair<int, int>>()) - a;
		if (p - 1 <= n) {
			long long cur;
			if (p - 1 >= i) cur = 1ll * (n - p + 1) * a[i].second;
			else cur = a[i].first + 1ll * (n - p) * a[i].second;
			ans = max(ans, s[p - 1] + cur);
		}
	}
	cout << ans << '\n';
}

int32_t main() {
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