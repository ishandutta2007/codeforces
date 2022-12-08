#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if (!a && !c) {
		std::cout << "0\n";
		return;
	}
	if (!a || !c) {
		std::cout << "1\n";
		return;
	}
	b *= c, a *= d;
	i64 g = std::gcd(a, b);
	a /= g;
	b /= g;
	if (a == 1 && b == 1) std::cout << "0\n";
	else if (a == 1 || b == 1) std::cout << "1\n";
	else std::cout << "2\n";
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