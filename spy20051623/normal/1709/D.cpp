#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5;
int st[20][N];

void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> st[0][i];
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 1, k = 1 + (1 << (i - 1)); j + (1 << i) <= m + 1; ++j, ++k) {
			st[i][j] = std::max(st[i - 1][j], st[i - 1][k]);
		}
	}
	int q;
	std::cin >> q;
	while (q--) {
		int x1, y1, x2, y2, k;
		std::cin >> x1 >> y1 >> x2 >> y2 >> k;
		if (y1 > y2) {
			std::swap(x1, x2);
			std::swap(y1, y2);
		}
		if (abs(y1 - y2) % k || abs(x1 - x2) % k) {
			std::cout << "NO\n";
			continue;
		}
		int d = std::__lg(y2 - y1);
		int mx = std::max(st[d][y1], st[d][y2 - (1 << d) + 1]);
		int f = std::max(x1, x2);
		if (f > mx) {
			std::cout << "YES\n";
			continue;
		}
		int p = (mx - f) / k + 1;
		if (f + p * k > n) std::cout << "NO\n";
		else std::cout << "YES\n";
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}