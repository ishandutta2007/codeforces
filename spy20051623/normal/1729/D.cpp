#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		c[i] = b[i] - a[i];
	}
	std::sort(c.begin(), c.end());
	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		while (l < r && c[l] + c[r] < 0) ++l;
		if (l < r) ++ans, --r, ++l;
		else break;
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