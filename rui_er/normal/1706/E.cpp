//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n, m, q, now, dfn[N], tms, dis[N], id[N], fa[N][20], val[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Edge {
	int u, v, w;
	Edge(int x=0, int y=0, int z=0) : u(x), v(y), w(z) {}
}G[N];
vector<int> e[N];
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
	dsu.init(2*n-1);
	sort(G+1, G+1+m, [](const Edge& x, const Edge& y) {
		return x.w < y.w;
	});
	now = n;
	rep(i, 1, m) {
		ll u = dsu.find(G[i].u), v = dsu.find(G[i].v), w = G[i].w;
		if(u != v) {
			val[++now] = w;
			dsu.merge(u, now);
			dsu.merge(v, now);
			e[now].push_back(u);
			e[now].push_back(v);
		}
	}
}
void dfs(int u, int f) {
	dfn[u] = ++tms;
	dis[u] = dis[f] + 1;
	fa[u][0] = f;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int v : e[u]) dfs(v, u);
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 19, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
struct SparseTable {
	int lg[N], mx[N][20], mn[N][20];
	void init(int* a, int n) {
		lg[0] = -1;
		rep(i, 1, n) lg[i] = lg[i>>1] + 1;
		rep(i, 1, n) mx[i][0] = mn[i][0] = a[i];
		rep(j, 1, 19) {
			rep(i, 1, n-(1<<j)+1) {
				mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
				mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int qmax(int l, int r) {
		int k = lg[r-l+1];
		return max(mx[l][k], mx[r-(1<<k)+1][k]);
	}
	int qmin(int l, int r) {
		int k = lg[r-l+1];
		return min(mn[l][k], mn[r-(1<<k)+1][k]);
	}
}st;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &m, &q);
		rep(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[i] = Edge(u, v, i);
		}
		kruskal();
		dfs(now, 0);
		st.init(dfn, now);
		rep(i, 1, now) id[dfn[i]] = i;
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int u = id[st.qmax(l, r)], v = id[st.qmin(l, r)];
			if(u == v) printf("%d%c", 0, " \n"[!q]);
			else printf("%d%c", val[LCA(u, v)], " \n"[!q]);
		}
		tms = 0;
		rep(i, 1, now) e[i].clear();
	}
	return 0;
}