#include <bits/stdc++.h>

using i64 = long long;

int G(std::vector<int> &v) {
	int g = 0;
	for (int i: v) g = std::gcd(g, i);
	return g;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	if (G(a) == 1) {
		std::cout << "0\n";
		return;
	}
	std::vector<int> b = a;
	b[n - 1] = std::gcd(b[n - 1], n);
	if (G(b) == 1) {
		std::cout << "1\n";
		return;
	}
	b = a;
	b[n - 2] = std::gcd(b[n - 2], n - 1);
	if (G(b) == 1) std::cout << "2\n";
	else std::cout << "3\n";
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