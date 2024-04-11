// Problem: CF1624G MinOr Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1624G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, m;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Edge {
	int u, v, w;
	Edge(int a=0, int b=0, int c=0) : u(a), v(b), w(c) {}
}e[N];
struct Dsu {
	int fa[N];
	void init(int x) {rep(i, 1, x) fa[i] = i;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		fa[u] = v;
		return 1;
	}
}dsu;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		int ans = 0;
		per(j, 30, 0) {
			dsu.init(n);
			int con = n;
			rep(i, 1, m) {
				if((e[i].w >> j) & 1) continue;
				if((e[i].w | ans) >= ((1 << j) | ans)) continue;
				con -= dsu.merge(e[i].u, e[i].v);
			}
			if(con > 1) ans |= 1 << j;
		}
		printf("%d\n", ans);
	}
	return 0;
}