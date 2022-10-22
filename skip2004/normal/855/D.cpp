#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
int n, q;
int bz[20][maxn];
int sum[maxn], dep[maxn];

inline int rt(int x) { for(int i = 19;i >= 0;--i) if(bz[i][x]) x = bz[i][x]; return x; }
inline int lca(int x, int y) {
	if(dep[x] > dep[y]) std::swap(x, y);
	for(int d = dep[y] - dep[x];d;d &= d - 1) y = bz[__builtin_ctz(d)][y];
	for(int i = 19;i >= 0;--i) if(bz[i][x] != bz[i][y]) x = bz[i][x], y = bz[i][y];
	return x == y ? x : bz[0][x];
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 1, fa;i <= n;++i) {
		cin >> fa >> sum[i];
		if(fa != -1) {
			sum[i] += sum[fa];
			dep[i] = dep[fa] + 1;
			bz[0][i] = fa;
		}
	}
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j <= n;++j) {
			bz[i][j] = bz[i - 1][bz[i - 1][j]];
		}
	}
	cin >> q;
	for(int i = 0;i < q;++i) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(rt(x) != rt(y)) {
			cout << "NO" << '\n';
			continue;
		}
		int lc = lca(x, y);
		bool yes = sum[x] == sum[lc] && y != lc;
		if(opt == 1) yes &= sum[y] == sum[lc] && x == lc;
		else yes &= sum[y] - sum[lc] == dep[y] - dep[lc];
		cout << (yes ? "YES" : "NO") << '\n';
	}
}