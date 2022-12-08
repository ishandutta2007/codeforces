#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	i64 ans = 1ll * n * (n + 1) / 2;
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) ans += 1ll * (n - i) * i;
	}
	while (m--) {
		int i, x;
		std::cin >> i >> x;
		if (i != 1 && a[i - 1] == a[i - 2]) ans += 1ll * (n - i + 1) * (i - 1);
		if (i != n && a[i - 1] != a[i]) ans -= 1ll * (n - i) * i;
		a[i - 1] = x;
		if (i != 1 && a[i - 1] == a[i - 2]) ans -= 1ll * (n - i + 1) * (i - 1);
		if (i != n && a[i - 1] != a[i]) ans += 1ll * (n - i) * i;
		std::cout << ans << '\n';
	}
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}