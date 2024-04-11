#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> mx(k);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		mx[i % k] = std::max(mx[i % k], x);
	}
	i64 ans = 0;
	for (int i: mx) ans += i;
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