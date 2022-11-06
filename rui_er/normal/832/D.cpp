//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, q, dis[N], fa[N][20];
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}
void dfs(int u, int f) {
	dis[u] = dis[f] + 1;
	fa[u][0] = f;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f) dfs(v, u);
	}
}
int lca(int x, int y) {
	if(dis[x] < dis[y]) swap(x, y);
	per(i, 19, 0) if(dis[fa[x][i]] >= dis[y]) x = fa[x][i];
	if(x == y) return x;
	per(i, 19, 0) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int f(int x, int y, int z) {return (x == y) * (dis[z] - dis[x]) - max(dis[x], dis[y]);}
int calc(int x, int y, int z) {
	int xy = lca(x, y), yz = lca(y, z), xz = lca(x, z);
	int r1 = dis[z] + 1 + f(xz, yz, xy);
	int r2 = dis[x] + 1 + f(xy, xz, yz);
	int r3 = dis[y] + 1 + f(xy, yz, xz);
	return max(r1, max(r2, r3));
}

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 2, n) {int p; scanf("%d", &p); add(i, p);}
	dfs(1, 0);
	while(q--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		printf("%d\n", calc(x, y, z));
	}
	return 0;
}