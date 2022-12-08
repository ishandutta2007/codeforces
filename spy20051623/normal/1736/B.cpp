#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n + 1, 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		b[i] = std::lcm(b[i], a[i]);
		b[i + 1] = std::lcm(b[i + 1], a[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != std::gcd(b[i], b[i + 1])) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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