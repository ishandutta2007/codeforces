#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<i64> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int l = 0, r = n;
	i64 ans = -1e18;
	for (int i = 0; i <= n; ++i) {
		i64 sum = s[i] - 1ll * k * i;
		for (int j = 1; j < 32 && i + j <= n; ++j) {
			sum += a[i + j] >> j;
		}
		ans = std::max(ans, sum);
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