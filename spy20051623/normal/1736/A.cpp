#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] && !b[i]) ++x;
		if (!a[i] && b[i]) ++y;
	}
	if (!x) std::cout << y << '\n';
	else if (!y) std::cout << x << '\n';
	else std::cout << abs(x - y) + 1 << '\n';
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