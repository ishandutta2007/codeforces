#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	int mn = 1e9;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mn = std::min(mn, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = std::max(ans, a[i] / k);
	}
	for (int i = 1; i <= mn; ++i) {
		int mx = 0;
		for (int j = 0; j < n; ++j) {
			int p = a[j] / i;
			mx = std::max(mx, a[j] / std::min(p, k));
		}
		ans = std::min(ans, mx - i);
	}
	std::cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}