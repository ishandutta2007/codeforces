#include<bits/stdc++.h>
using namespace std;

const int N = 10005, E = 10005, inf = 0x3f3f3f3f;
struct Edge {
	int u, v, w;
} edge[E];
struct Graph {
	int v, nxt;
} link[3][E];
int x[E], y[E], head[2][N], tot1, tot2, n, m, k = 0, dis[N];
bool vis[3][N], ind[N];

inline void addedge(int u, int v) {
	link[0][++tot1].v = v, link[0][tot1].nxt = head[0][u], head[0][u] = tot1;
	link[1][++tot2].v = u, link[1][tot2].nxt = head[1][v], head[1][v] = tot2;
}

inline void insedge(int u, int v, int wgt, int rev) {
	edge[++k].u = u, edge[k].v = v, edge[k].w = -1;
	edge[++k].u = v, edge[k].v = u, edge[k].w = 2;
}

inline void dfs(int id, int u) {
	if(vis[id][u]) return;
	vis[id][u] = 1;
	for(int i = head[id][u]; i; i = link[id][i].nxt) dfs(id, link[id][i].v);
}

inline bool SPFA_is_dead() {
	memset(dis, 0x3f, sizeof(dis)); dis[1] = 0;
	for(register int i = 1; i <= n; i++) 
		for(register int j = 1; j <= k; j++) 
			dis[edge[j].v] = min(dis[edge[j].v], dis[edge[j].u] + edge[j].w);
	for(register int i = 1; i <= k; i++) if(dis[edge[i].u] + edge[i].w < dis[edge[i].v]) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for(register int i = 1; i <= m; i++) scanf("%d%d", &x[i], &y[i]), addedge(x[i], y[i]);
	dfs(0, 1), dfs(1, n);
	for(register int i = 1; i <= m; i++) if((vis[0][x[i]]&&vis[1][x[i]])&&(vis[0][y[i]]&&vis[1][y[i]])) insedge(x[i], y[i], -1, 9);
	bool flag = SPFA_is_dead();
	if(!flag || dis[n] == inf) { printf("No"); return 0; }
	printf("Yes\n");
	for(int i = 1; i <= m; i++) printf("%d\n", (vis[0][x[i]]&&vis[1][x[i]])&&(vis[0][y[i]]&&vis[1][y[i]])?(dis[x[i]] - dis[y[i]]):1);
	return 0;
}