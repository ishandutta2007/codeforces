#include <bits/stdc++.h>

using i64 = long long;

int q1 = 0, q2 = 0;

char qry1(int x) {
	assert(++q1 <= 26);
	std::cout << "? 1 " << x << std::endl;
	char y;
	std::cin >> y;
	return y;
}

int qry2(int l, int r) {
	assert(++q2 <= 6000);
	std::cout << "? 2 " << l << ' ' << r << std::endl;
	int y;
	std::cin >> y;
	return y;
}

void solve() {
	int n;
	std::cin >> n;
	std::string s(n + 1, 0);
	std::vector<int> cnt(n + 1);
	s[1] = qry1(1);
	cnt[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cnt[i] = qry2(1, i);
		if (cnt[i] != cnt[i - 1]) s[i] = qry1(i);
	}
	std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) {
			int l = 1, r = cnt[i - 1], ans = -1;
			while (l <= r) {
				int m = (l + r) >> 1, p = -1;
				for (int j = i - 1; j >= 1; --j) {
					if (__builtin_popcount(g[j][i - 1]) == m) {
						p = j;
						break;
					}
				}
				int u = qry2(p, i);
				if (u == m) r = m - 1, ans = m;
				else l = m + 1;
			}
			for (int j = i - 1; j >= 1; --j) {
				if (__builtin_popcount(g[j][i - 1]) == ans) {
					s[i] = s[j];
					break;
				}
			}
		}
		int now = 0;
		for (int j = i; j >= 1; --j) {
			now |= 1 << (s[j] - 'a');
			g[j][i] = now;
		}
	}
	std::cout << "! " << s.substr(1) << std::endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//#else
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}