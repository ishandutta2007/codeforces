//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, fa[N][20], dis[N], sz[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void add(int u, int v) {
	e[u].push_back(v);
	e[v].push_back(u);
}
void dfs(int u, int f) {
	dis[u] = dis[f] + 1;
	sz[u] = 1;
	fa[u][0] = f;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(auto v : e[u]) {
		if(v != f) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
int lca(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 19, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] != fa[v][i]) {u = fa[u][i]; v = fa[v][i];}
	return fa[u][0];
}
int jump(int u, int d) {
	per(i, 19, 0) if((1 << i) <= d) {
		u = fa[u][i];
		d -= 1 << i;
	}
	return u;
}
int calc(int u, int v) {
	if(u == v) return n;
	int p = lca(u, v);
	int d = dis[u] + dis[v] - dis[p] * 2;
	if(d & 1) return 0;
	int ans = 0;
	if(dis[u] == dis[v]) {
		ans += n - sz[p];
		int k = jump(u, d/2-1), r = jump(v, d/2-1);
		ans += sz[p] - sz[k] - sz[r];
		return ans;
	}
	if(dis[u] < dis[v]) swap(u, v);
	int k = jump(u, d/2), r = jump(u, d/2-1);
	ans += sz[k] - sz[r]; 
	return ans;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(1, 0);
	scanf("%d", &m);
	while(m --> 0) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", calc(u, v));
	}
    return 0;
}