#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s, t;
	std::cin >> s >> t;
	s = '+' + s + '+';
	t = '-' + t + '-';
	std::vector<int> pre(m + 2, n + 1), suf(m + 2, 0);
	pre[0] = 0;
	suf[m + 1] = n + 1;
	for (int i = 1, p = 1; i <= n; ++i) {
		if (s[i] == t[p]) pre[p++] = i;
	}
	for (int i = n, p = m; i >= 1; --i) {
		if (s[i] == t[p]) suf[p--] = i;
	}
	std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 2));
	for (int i = 0; i <= n - m; ++i) {
		for (int j = n - i, k = m, p = j, q = k; k >= 0; --j, --k) {
			if (s[j] != t[k]) {
				while (p != j) {
					int d = p - j;
					f[p--][q--] = d;
				}
				--p, --q;
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i && j <= m; ++j) {
			int p = n + 1 - i, q = m + 1 - j;
			if (suf[q] < p) continue;
			int d = f[p - 1][q - 1];
			int pp = p - d, qq = q - d;
			if (pre[qq - 1] > pp - 1) continue;
			if (pp == 1) ans = std::min(ans, i + pp + pp - qq - 1);
			else ans = std::min(ans, i + 1 + pp + pp - qq - 1);
		}
	}
	std::cout << (ans > 1e8 ? -1 : ans) << '\n';
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