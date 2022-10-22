#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned u32;
using std::cin;
using std::cout;
const int maxn = 100100;
int n, m;
 
u32 w[maxn];
int a[maxn], aw[maxn];
int size[maxn], son[maxn], dfn[maxn];
int fa[maxn];
int head[maxn], next[maxn];
 
template<class ptr>
inline void tr(ptr a) {
	static int b[maxn];
	memcpy(b + 1, a + 1, n << 2);
	for(int i = 1;i <= n;++i) a[dfn[i]] = b[i];
}
inline void link(int fa, int x) { next[x] = head[fa], head[fa] = x; }
 
inline void dfs0(int x) {
	size[x] = 1;
	for(int i = head[x];i;i = next[i]) {
		dfs0(i);
		size[x] += size[i];
		if(size[i] > size[son[x]]) son[x] = i;
	}
	w[x] = (u32) size[x] * size[x];
}
inline void dfs1(int x) {
	static int tot;
	dfn[x] = ++ tot;
	if(son[x]) dfs1(son[x]);
	for(int i = head[x];i;i = next[i]) if(i != son[x]) dfs1(i);
}
ll su = 0;
 
 
inline double calc() { return (double) su / n / n; }
 
inline void add(int x, int v) {
	while(x) {
		su += (2ll * size[x] * v + (ll) v * v) * aw[x];
		size[x] += v;
		w[x] = size[x] * size[x];
		x = fa[x];
	}
}
 
inline void change(int x, int y) {
	add(fa[x], -size[x]);
	add(y, size[x]);
 
	fa[x] = y;
	su -= (ll) w[x] * aw[x];
	aw[x] = a[x] - a[fa[x]];
	su += (ll) w[x] * aw[x];
}
 
inline bool is_anc(int x, int y) {
	while(y) {
		if(x == y) return 1;
		y = fa[y];
	}
	return 0;
}
 
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 2;i <= n;++i) {
		cin >> fa[i];
		link(fa[i], i);
	}
	dfs0(1);
	dfs1(1);
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i) {
		aw[i] = a[i] - a[fa[i]];
	}
	for(int i = 1;i <= n;++i) su += (ll) w[i] * aw[i];
 
	for(int i = 1;i <= n;++i) {
		fa[i] = dfn[fa[i]];
	}
 
	tr(fa); tr(a); tr(w); tr(aw); tr(size);
 
	printf("%.10lf\n", calc());
	cin >> m;
	for(int i = 1, x, y;i <= m;++i) {
		char ch;
		cin >> ch >> x >> y;
		x = dfn[x];
 
		if(ch == 'P') {
			y = dfn[y];
			if(is_anc(x, y)) {
				change(y, x);
			} else {
				change(x, y);
			}
		} else { 
			const int delt = y - a[x];
			a[x] += delt, aw[x] += delt, su += (ll) w[x] * delt;
			ll sm = 0;
			for(int i = 1;i <= n;++i) if(fa[i] == x) sm += w[i], aw[i] -= delt;
			su -= sm * delt;
		}
		printf("%.10lf\n", calc());
	}
}