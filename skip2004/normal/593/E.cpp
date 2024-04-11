#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int mod = 1e9 + 7;

struct mat { int a[20][20]; } EP;
mat ans;


inline mat mul(const mat & x, mat y, int is = 0) {
	mat res = EP;
	rep(i, 0, 19) rep(j, i + 1, 19) std::swap(y.a[i][j], y.a[j][i]);
	rep(i, 0, is ? 0 : 19) rep(k, 0, 19) {
		u64 s = 0;
		rep(j, 0, 19) s += (u64) x.a[i][j] * y.a[k][j];
		res.a[i][k] = s % mod;
	}
	return res;
}

int n, m, q;
inline int node(int x, int y) { return x * m + y; }
int bad[100][100];
inline int good(u32 x, u32 y) {
	return x < n && y < m && !bad[x][y];
}
inline void solve(int clk) {
	mat ts = EP;
	rep(i, 0, n - 1) rep(j, 0, m - 1) if(good(i, j)) {
		if(good(i - 1, j)) ++ ts.a[node(i, j)][node(i - 1, j)];
		if(good(i + 1, j)) ++ ts.a[node(i, j)][node(i + 1, j)];
		if(good(i, j - 1)) ++ ts.a[node(i, j)][node(i, j - 1)];
		if(good(i, j + 1)) ++ ts.a[node(i, j)][node(i, j + 1)];
		++ ts.a[node(i, j)][node(i, j)];
	}
	for(;clk;clk >>= 1, ts = mul(ts, ts)) if(clk & 1) {
		ans = mul(ans, ts, 1);
	}
}
int main() {
//	freopen("1.in", "r", stdin);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> q;
	int prv = 1;
	ans.a[0][0] = 1;
	rep(i, 1, q) {
		int op, x, y, t;
		cin >> op >> x >> y >> t;
		-- x, -- y;
		solve(t - prv);
		prv = t;
		if(op == 1) cout << ans.a[0][node(x, y)] << '\n';
		if(op == 2) ans.a[x][y] = 0, bad[x][y] = 1;
		if(op == 3) bad[x][y] = 0;
	}
}