#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++i)
using std::cin;
using std::cout;
const int maxn = 2510;
int n, m;
template<class T0, class T1>
inline void up(T0 & x, const T1 & y) {
	if(x < y) x = y;
}

const int empty = 0;
const int jack = 1;
const int jill = 2;

using AI = short[maxn];
struct cluster {
	int u, v, size;
	short mem[3][3][maxn];
	short*dp[3][3];
	inline cluster() { rep(x,0,2)rep(y,0,2)dp[x][y]=mem[x][y]; }
	inline void swap() {
		std::swap(u,v);
		std::swap(dp[0][1],dp[1][0]);
		std::swap(dp[0][2],dp[2][0]);
		std::swap(dp[1][2],dp[2][1]);
	}
} cls[maxn * 3 / 2];

cluster *id[maxn * 3 / 2];
int t[maxn];

static int res[3][3][maxn];
inline bool try_rake(int x, int y) {
	cluster& a = *id[x], &b =*id[y];
	int ok = 0;
	for(int i = 0;i < 4;++i) {
		if(a.v==b.u&&t[b.v]==1) { ok = 1; break; }
		(i&1?a:b).swap();
	}
	if(ok) {
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size + 1) res[x][y][i] = -n;
		rep(x0, 0, 2) rep(y0, 0, 2) rep(i0, 0, a.size) if(a.dp[x0][y0][i0] >= 0) {
			rep(y1, 0, 2) rep(i1, 0, b.size) {
				up(res[x0][y0][i0 + i1 + (y1 == jack)], a.dp[x0][y0][i0] + b.dp[y0][y1][i1] + (y1 == jill));
			}
		}
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size + 1) a.dp[x][y][i] = res[x][y][i];
		a.size += b.size + 1;
		-- t[a.v], t[b.v] = 0;
		return 1;
	}
	return 0;
}

inline bool try_compress(int x, int y) {
	cluster& a = *id[x], &b =*id[y];
	int ok = 0;
	for(int i = 0;i < 4;++i) {
		if(t[a.v]==2&&t[b.u]==2&&a.v==b.u&&a.u!=b.v) { ok = 1; break; }
		(i&1?a:b).swap();
	}
	if(ok) {
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size + 1) res[x][y][i] = -n;
		rep(x0, 0, 2) rep(y0, 0, 2) rep(i0, 0, a.size) if(a.dp[x0][y0][i0] >= 0) {
			rep(y1, 0, 2) rep(i1, 0, b.size) {
				up(res[x0][y1][i0 + i1 + (y0 == jack)], a.dp[x0][y0][i0] + b.dp[y0][y1][i1] + (y0 == jill));
			}
		}
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size + 1) a.dp[x][y][i] = res[x][y][i];
		a.size += b.size + 1;
		t[a.v] = 0, a.v = b.v;
		return 1;
	}
	return 0;
}

inline bool try_twist(int x, int y) {
	cluster& a = *id[x], &b =*id[y];
	if(a.u > a.v) a.swap();
	if(b.u > b.v) b.swap();
	if(a.u == b.u && a.v == b.v) {
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size) res[x][y][i] = -n;
		rep(x0, 0, 2) rep(y0, 0, 2) rep(i0, 0, a.size) if(a.dp[x0][y0][i0] >= 0) 
			rep(i1, 0, b.size) up(res[x0][y0][i0 + i1], a.dp[x0][y0][i0] + b.dp[x0][y0][i1]);
		rep(x, 0, 2) rep(y, 0, 2) rep(i, 0, a.size + b.size) a.dp[x][y][i] = res[x][y][i];
		a.size += b.size;
		-- t[a.u], -- t[a.v];
		return 1;
	}
	return 0;
}

int ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	if(n==1){
		puts("1 0");
		return 0;
	}
	for(int i = 0;i < m;++i) {
		cin >> cls[i].u >> cls[i].v, id[i] = cls + i;
		rep(x, 0, 2) rep(y, 0, 2) {
			cls[i].dp[x][y][0] = x && y && x != y ? -n : 0;
		}
		++ t[cls[i].u];
		++ t[cls[i].v];
	}
	std::mt19937 rd;
	for(;m != 1;) {
		int x = rd() % m, y = rd() % m;
		if(x == y) continue;
		if(try_rake(x, y)) {
			std::swap(id[y], id[--m]);
			continue;
		}
		if(try_compress(x, y)) {
			std::swap(id[y], id[--m]);
			continue;
		}
		if(try_twist(x, y)) {
			std::swap(id[y], id[--m]);
			continue;
		}
	}
	rep(x, 0, 2) rep(y, 0, 2) rep(k, 0, (*id)->size) {
		up(ans[k + (x == jack) + (y == jack)], (*id) -> dp[x][y][k] + (x == jill) + (y == jill));
	}
	rep(i, 0, n) {
		cout << ans[i] << ' ';
	}
}