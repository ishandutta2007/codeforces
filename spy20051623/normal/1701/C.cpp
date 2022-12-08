#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m), c(n + 1);
	for (int i = 0; i < m; ++i) {
		std::cin >> a[i];
		++c[a[i]];
	}
	int l = 1, r = 5e5, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		i64 sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (mid >= c[i]) sum += c[i] + (mid - c[i]) / 2;
			else sum += mid;
		}
		if (sum >= m) ans = mid, r = mid - 1;
		else l = mid + 1;
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