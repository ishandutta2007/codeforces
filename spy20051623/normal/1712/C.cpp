#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int p = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (b[a[i]]) a[i] = 0;
		if (b[a[i + 1]]) a[i + 1] = 0;
		if (a[i] > a[i + 1]) {
			for (; p <= i; ++p) b[a[p]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += b[i];
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