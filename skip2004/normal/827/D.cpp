#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using std::cin;
using std::cout;
#define ctz __builtin_ctz
const int maxn = 200200;
int n, m;
inline void up(int & x, int y) {
	if(x < y) {
		x = y;
	}
}
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
struct T {
	int u, v, c, id;
} a[maxn];
inline int cmp0(const T & x, const T & y) { return x.c < y.c; }
int fa[maxn];
int on[maxn];
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
namespace tr {
	struct edge {
		int to, nxt, v;
	} way[maxn << 1];
	int h[maxn], num;
	inline void link(int x, int y, int v) {
		way[++num] = {y, h[x], v}, h[x] = num;
		way[++num] = {x, h[y], v}, h[y] = num;
	}
	int bz[20][maxn], max[20][maxn], tag[20][maxn], dep[maxn];

	inline void dfs0(int x, int fa = 0) {
		dep[x] = dep[fa] + 1;
		tag[0][x] = 2e9;
		for(int i = 1;i < 18;++i) {
			bz[i][x] = bz[i - 1][bz[i - 1][x]];
			max[i][x] = std::max(max[i - 1][x], max[i - 1][bz[i - 1][x]]);
			tag[i][x] = 2e9;
		}
		for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
			bz[0][way[i].to] = x;
			max[0][way[i].to] = way[i].v;
			dfs0(way[i].to, x);
		}
	}

	inline int ask(int x, int y, int v) {
		int ans = 0;
		if(dep[x] > dep[y]) std::swap(x, y);
		for(int i = dep[y] - dep[x];i;i &= i - 1) {
			up(ans, max[ctz(i)][y]);
			down(tag[ctz(i)][y], v);
			y = bz[ctz(i)][y];
		}
		for(int i = 17;i >= 0;--i) if(bz[i][x] != bz[i][y]) {
			up(ans, max[i][x]);
			up(ans, max[i][y]);
			down(tag[i][x], v);
			down(tag[i][y], v);
			x = bz[i][x];
			y = bz[i][y];
		}
		if(x != y) {
			up(ans, max[0][x]);
			up(ans, max[0][y]);
			down(tag[0][x], v);
			down(tag[0][y], v);
		}
		return ans;
	}
	inline void pushdown() {
		for(int i = 17;i >= 1;--i) {
			for(int x = 1;x <= n;++x) {
				down(tag[i - 1][x], tag[i][x]);
				down(tag[i - 1][bz[i - 1][x]], tag[i][x]);
			}
		}
	}
}

int ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;++i) {
		cin >> a[i].u >> a[i].v >> a[i].c;
		a[i].id = i;
	}
	std::sort(a, a + m, cmp0);
	for(int i = 1;i <= n;++i) {
		fa[i] = i;
	}
	for(int i = 0;i < m;++i) {
		if(find(a[i].u) != find(a[i].v)) {
			on[a[i].id] = 1;
			fa[find(a[i].u)] = find(a[i].v);
			tr::link(a[i].u, a[i].v, a[i].c);
		}
	}
	tr::dfs0(1);
	for(int i = 0;i < m;++i) {
		if(!on[a[i].id]) {
			ans[a[i].id] = tr::ask(a[i].u, a[i].v, a[i].c);
		}
	}
	tr::pushdown();
	for(int i = 0;i < m;++i) {
		if(on[a[i].id]) {
			ans[a[i].id] = tr::tag[0][tr::dep[a[i].u] < tr::dep[a[i].v] ? a[i].v : a[i].u];
		}
	}
	for(int i = 0;i < m;++i) {
		cout << (ans[i] < 1.5e9 ? ans[i] - 1 : -1) << ' ';
	}
}