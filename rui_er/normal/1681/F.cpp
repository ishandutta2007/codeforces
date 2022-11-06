// Problem: CF1681F Unique Occurrences
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1681F
// Memory Limit: 1000 MB
// Time Limit: 6000 ms
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
const int N = 1e6+5;

int n, sz[N], siz[N], fa[N];
stack<int> path[N];
vector<tuple<int, int> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f) {
	// fprintf(stderr, "DFS %d %d\n", u, f);
	sz[u] = 1;
	for(auto i : e[u]) {
		int v = get<0>(i), w = get<1>(i);
		if(v == f) continue;
		fa[v] = path[w].top();
		path[w].push(v);
		dfs(v, u);
		sz[u] += sz[v];
		siz[v] += sz[v];
		siz[fa[v]] -= sz[v];
		path[w].pop();
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}
	rep(i, 1, n) {
		path[i].push(n+i);
		siz[n+i] = n;
	}
	dfs(1, 0);
	ll ans = 0;
	// rep(i, 1, n) fprintf(stderr, "%d%c", fa[i], " \n"[i==n]);
	// rep(i, 1, n) fprintf(stderr, "%d%c", siz[i], " \n"[i==n]);
	rep(i, 1, n) ans += 1LL * siz[fa[i]] * siz[i];
	printf("%lld\n", ans);
	return 0;
}