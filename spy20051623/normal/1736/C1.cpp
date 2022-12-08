#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1), c(n + 2, n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		b[i] = i - a[i] + 1;
	}
	for (int i = n; i >= 1; --i) {
		if (b[i] >= 1) c[b[i]] = i;
	}
	i64 ans = 0;
	for (int i = n; i >= 1; --i) {
		c[i] = std::min(c[i], c[i + 1]);
		ans += c[i + 1] - i;
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