#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 5;
int a[N], st1[20][20][N], st2[20][20][N];

void solve() {
	int n, q;
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n - 1; ++i) {
		st1[0][0][i] = std::min(a[i], a[i + 1]);
		st2[0][0][i] = std::max(a[i], a[i + 1]);
	}
	for (int i = 1; i < 18; ++i) {
		for (int j = 1, k = 1 + (1 << (i - 1)); k <= n - 1; ++j, ++k) {
			st1[0][i][j] = std::min(st1[0][i - 1][j], st1[0][i - 1][k]);
			st2[0][i][j] = std::max(st2[0][i - 1][j], st2[0][i - 1][k]);
		}
	}
	for (int i = 1; i < 18; ++i) {
		for (int j = 1; j <= n - 1; ++j) {
			int l = st1[i - 1][0][j], r = st2[i - 1][0][j] - 1;
			int d = std::__lg(r - l + 1);
			st1[i][0][j] = std::min(st1[i - 1][d][l], st1[i - 1][d][r - (1 << d) + 1]);
			st2[i][0][j] = std::max(st2[i - 1][d][l], st2[i - 1][d][r - (1 << d) + 1]);
		}
		for (int j = 1; j < 18; ++j) {
			for (int k = 1, l = 1 + (1 << (j - 1)); l <= n - 1; ++k, ++l) {
				st1[i][j][k] = std::min(st1[i][j - 1][k], st1[i][j - 1][l]);
				st2[i][j][k] = std::max(st2[i][j - 1][k], st2[i][j - 1][l]);
			}
		}
	}
	while (q--) {
		int l, r, ll, rr, ans = 0, fd = 0;
		std::cin >> l >> r;
		if (l == 1 && r == n) {
			std::cout << "0\n";
			continue;
		}
		if (l == r) {
			std::cout << "-1\n";
			continue;
		}
		--r;
		for (int i = 17; i >= 0; --i) {
			int d = std::__lg(r - l + 1);
			ll = std::min(st1[i][d][l], st1[i][d][r - (1 << d) + 1]);
			rr = std::max(st2[i][d][l], st2[i][d][r - (1 << d) + 1]);
			if (ll != 1 || rr != n) ans += 1 << i, l = ll, r = rr - 1;
			else fd = 1;
		}
		std::cout << (fd ? ans + 1 : -1) << '\n';
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