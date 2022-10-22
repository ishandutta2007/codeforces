#include<bits/stdc++.h>
const int maxn = 1010;
#define rep(i, l, r) for(int i = l;i <= r;++i) 
using std::cin;
using std::cout;
int n, k, p;
int a0[maxn], a1[maxn];
inline void input(int * a) {
	int cnt = 0, x; cin >> cnt;
	for(int i = 0;i < cnt;++i) {
		cin >> x, a[x] = 1;
	}
}
int g0[maxn][51][51];
int g1[maxn][51][51];
inline void up(int & x, int y) {
	if(x < y) {
		x = y;
	}
}
inline void trans(int c0, int c1) {
	rep(i, 0, p) rep(j, 1, k) rep(l, 1, k) {
		const int Nj = j == k ? k : j + 1;
		const int Nl = l == k ? k : l + 1;
		const int can = (j < k && c0) || (l < k && c1);
		up(g1[i][Nj][Nl], g0[i][j][l] + can);
		up(g1[i + 1][Nj][1], g0[i][j][l] + (can || c1));
		up(g1[i + 1][1][Nl], g0[i][j][l] + (can || c0));
		up(g1[i + 2][1][1], g0[i][j][l] + (can || c0 || c1));
	}
	rep(i, 0, p) rep(j, 1, k) rep(l, 1, k) {
		g0[i][j][l] = g1[i][j][l];
		g1[i][j][l] = -1e9;
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> p >> k;
	input(a0), input(a1);
	if(k * p >= n * 2) {
		int ans = 0;
		for(int i = 1;i <= n;++i) ans += a0[i] || a1[i];
		cout << ans << '\n';
		return 0;
	}
	rep(i, 0, p) rep(j, 1, k) rep(l, 1, k) {
		g0[i][j][l] = g1[i][j][l] = -1e9;
	}
	g0[0][k][k] = 0;
	for(int i = 1;i <= n;++i) {
		trans(a0[i], a1[i]);
	}
	int ans = 0;
	rep(i, 1, k) rep(j, 1, k) up(ans, g0[p][i][j]);
	cout << ans << '\n';
}