// Problem: C. DFS Trees
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, vis[N], fa[N][20], dis[N], s[N];
vector<tuple<int, int> > e;
vector<int> t[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
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
void kruskal() {
	dsu.init(n);
	rep(i, 0, m-1) {
		int u = get<0>(e[i]), v = get<1>(e[i]);
		if(dsu.merge(u, v)) {
			vis[i] = 1;
			t[u].push_back(v);
			t[v].push_back(u);
		}
	}
}
void dfs1(int u, int f) {
	fa[u][0] = f;
	dis[u] = dis[f] + 1;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int v : t[u]) if(v != f) dfs1(v, u);
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 19, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
void dfs2(int u, int f) {
	s[u] += s[f];
	for(int v : t[u]) if(v != f) dfs2(v, u);
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e.emplace_back(u, v);
	}
	kruskal();
	dfs1(1, 0);
	rep(i, 0, m-1) {
		if(!vis[i]) {
			int u = get<0>(e[i]), v = get<1>(e[i]);
			int lca = LCA(u, v);
			if(dis[u] > dis[v]) swap(u, v);
			if(lca == u) {
				++s[1], ++s[v];
				int p = v;
				per(j, 19, 0) if(dis[fa[p][j]] > dis[u]) p = fa[p][j];
				--s[p];
			}
			else ++s[u], ++s[v];
		}
	}
	dfs2(1, 0);
	rep(i, 1, n) putchar(s[i]==m-n+1?'1':'0');
	puts("");
	return 0;
}