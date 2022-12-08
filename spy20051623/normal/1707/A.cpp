#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int x = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (x >= a[i]) b[i] = 1;
		else if (x < q) ++x, b[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << b[i];
	}
	std::cout << '\n';
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