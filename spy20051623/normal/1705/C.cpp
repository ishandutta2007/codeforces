#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, c, q;
	std::cin >> n >> c >> q;
	std::string s, t;
	std::cin >> s;
	std::vector<i64> l(c + 1), r(c + 1), f(c + 1);
	l[0] = 1, r[0] = n, f[0] = 1;
	for (int i = 1; i <= c; ++i) {
		std::cin >> l[i] >> r[i];
		f[i] = f[i - 1] + r[i - 1] - l[i - 1] + 1;
	}
	while (q--) {
		i64 x;
		std::cin >> x;
		int p = c + 1;
		while (p) {
			while (x < f[p - 1]) --p;
			--p;
			x = x - f[p] + l[p];
		}
		std::cout << s[x - 1] << '\n';
	}
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