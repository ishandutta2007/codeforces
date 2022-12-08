#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, m, k;
	std::cin >> n >> m >> k;
	std::vector<i64> a(k);
	for (int i = 0; i < k; ++i) {
		std::cin >> a[i];
	}
	i64 cnt = 0, f = 0;
	for (int i = 0; i < k; ++i) {
		if (a[i] / n >= 2) cnt += a[i] / n, f = std::max(f, a[i] / n);
	}
	if (cnt >= m && !(m % 2 && f == 2)) {
		std::cout << "YES\n";
		return;
	}
	std::swap(n, m);
	cnt = 0, f = 0;
	for (int i = 0; i < k; ++i) {
		if (a[i] / n >= 2) cnt += a[i] / n, f = std::max(f, a[i] / n);
	}
	if (cnt >= m && !(m % 2 && f == 2)) {
		std::cout << "YES\n";
		return;
	}
	std::cout << "NO\n";
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