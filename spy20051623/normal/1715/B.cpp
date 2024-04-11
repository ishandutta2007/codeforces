#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, k, b, s;
	std::cin >> n >> k >> b >> s;
	std::vector<i64> a(n);
	i64 x = b * k;
	if (s < x) {
		std::cout << "-1\n";
		return;
	}
	a[0] = x;
	s -= x;
	for (int i = 0; i < n; ++i) {
		if (s >= k - 1) a[i] += k - 1, s -= k - 1;
		else a[i] += s, s = 0;
	}
	if (s) {
		std::cout << "-1\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << ' ';
	}
	std::cout << "\n";
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