//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5; 

int n, m, fa[N], sz[N], son[N], ans[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne = 1, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}
void dfs(int u) {
	sz[u] = 1;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != fa[u]) {
			dfs(v);
			sz[u] += sz[v];
			if(sz[v] > sz[son[u]]) son[u] = v;
		}
	}
	if(!son[u]) ans[u] = u;
	else {
		ans[u] = ans[son[u]];
		while(ans[u] != u) {
			if(sz[son[ans[u]]] <= sz[u] / 2 && sz[u] - sz[ans[u]] <= sz[u] / 2) break;
			ans[u] = fa[ans[u]];
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 2, n) {
		scanf("%d", &fa[i]);
		add(i, fa[i]);
	}
	dfs(1);
	while(m --> 0) {
		int u;
		scanf("%d", &u);
		printf("%d\n", ans[u]);
	}
	return 0;
}