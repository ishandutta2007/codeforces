#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, d;
	std::cin >> n >> d;
	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<>());
	i64 m = n, ans = 0;
	for (int i = 0; i < n; ++i) {
		i64 x = d / a[i] + 1;
		if (x <= m) m -= x, ++ans;
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}