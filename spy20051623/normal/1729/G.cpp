#include <bits/stdc++.h>

using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	int n = s.length(), m = t.length();
	s = ' ' + s, t = ' ' + t;
	std::vector<int> nx(m + 1), p(1);
	for (int i = 2, j = 0; i <= m; ++i) {
		while (j && t[j + 1] != t[i]) j = nx[j];
		if (t[j + 1] == t[i]) ++j;
		nx[i] = j;
	}
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j && t[j + 1] != s[i]) j = nx[j];
		if (t[j + 1] == s[i]) ++j;
		if (j == m) j = nx[j], p.push_back(i);
	}
	p.push_back(1e9);
	int k = p.size();
	std::vector<int> x(k), y(k);
	x[0] = 0, y[0] = 1;
	for (int i = 1; i < k; ++i) {
		int u;
		for (int j = i - 1; j >= 0; --j) {
			if (p[j] <= p[i] - m) {
				u = j;
				break;
			}
		}
		int v = x[u];
		for (int j = u - 1; j >= 0 && p[j] > p[u] - m; --j) {
			v = std::min(v, x[j]);
		}
		x[i] = v + 1;
		for (int j = u; j >= 0 && p[j] > p[u] - m; --j) {
			if (x[j] == v) y[i] = (y[i] + y[j]) % mod;
		}
	}
	std::cout << x[k - 1] - 1 << ' ' << y[k - 1] << '\n';
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