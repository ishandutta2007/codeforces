#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	i64 ans = 1e9;
	for (int i = 1; i <= n; ++i) {
		bool ok = true;
		i64 sum = 0;
		for (int j = 0; j < i; ++j) {
			sum += a[j];
		}
		i64 now = 0, p = 0, q = 0;
		for (int j = 0; j < n; ++j) {
			now += a[j];
			if (now > sum) {
				ok = false;
				break;
			}
			if (now == sum) now = 0, q = std::max(q, j - p + 1), p = j + 1;
		}
		if (now) ok = false;
		if (ok) ans = std::min(ans, q);
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