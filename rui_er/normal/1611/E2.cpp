// Problem: CF1611E2 Escape The Maze (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1611E2
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

int T, n, k, tms[N], fa[N], nd;
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(int u, int f) {
	fa[u] = f;
	for(int v : e[u]) {
		if(v != f) {
			dfs1(v, u);
			chkmin(tms[u], tms[v]+1);
		}
	}
}
bool dfs2(int u, int f, int now) {
	if(u != 1 && (int)e[u].size() == 1) return 1;
	for(int v : e[u]) {
		if(tms[v] > now + 1 && v != f) {
			if(dfs2(v, u, now+1)) return 1;
		}
		else if(v != f) ++nd;
	}
	return 0;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		nd = 0;
		rep(i, 1, n) {
			tms[i] = n + 1;
			e[i].clear();
		}
		rep(i, 1, k) {
			int x;
			scanf("%d", &x);
			tms[x] = 0;
		}
		rep(i, 1, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1, 0);
		printf("%d\n", dfs2(1, 0, 0)?-1:nd);
	}
	return 0;
}