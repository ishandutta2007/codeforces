#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> a(n + 2), pre(n + 2), suf(n + 2);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 2; i < n; i += 2) {
		pre[i] = pre[i - 2] + std::max(0ll, std::max(a[i - 1] - a[i], a[i + 1] - a[i]) + 1);
	}
	for (int i = n - 1; i > 1; i -= 2) {
		suf[i] = suf[i + 2] + std::max(0ll, std::max(a[i - 1] - a[i], a[i + 1] - a[i]) + 1);
	}
	if (n & 1) {
		std::cout << pre[n - 1] << '\n';
		return;
	}
	i64 ans = 1e18;
	for (int i = 1; i < n; i += 2) {
		ans = std::min(ans, pre[i - 1] + suf[i + 2]);
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