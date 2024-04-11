#include<bits/stdc++.h>
using namespace std;

const int N = 100205, E = N * 2;
struct Edge {
	int u, v, nxt, w;
} edge[E];
int head[N], k = 1;
int n, m, ask;
long long dep[N], dis[N], d[50][N];
int tren[50], tree[E], top = 0;
int ins[N], vis[N];
int inq[N];
int f[N][25];
deque<int> q;

inline int get() {
	int x = 0; int f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

inline void addedge(int u, int v, int w) {
	edge[++k].v = v;
	edge[k].nxt = head[u];
	edge[k].w = w;
	edge[k].u = u;
	head[u] = k;
}

inline void insedge(int u, int v, int w) {
	addedge(u, v, w);
	addedge(v, u, w);
}

inline void dfs(int u, int fa, int w) {
	dep[u] = dep[fa]+1;
	f[u][0] = fa;
	dis[u] = dis[fa] + w;
	vis[u] = 1;
	for(register int i = 1; i <= 19; i++) f[u][i] = f[f[u][i-1]][i-1];
	for(register int i = head[u]; i; i = edge[i].nxt) {
		if(!vis[edge[i].v]) tree[i] = tree[i ^ 1] = 1, dfs(edge[i].v, u, edge[i].w);
	}
}

inline void slf_spfa(int s,int id) {
	memset(d[id], 0x3f, sizeof(d[id]));
	q.push_back(s), d[id][s] = 0, inq[s]=1;
	while(q.size()) {
		int u = q.front(); q.pop_front();
		inq[u]=0;
		for(register int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(d[id][v] > d[id][u] + edge[i].w) {
				d[id][v] = d[id][u] + edge[i].w;
				if(!inq[v]) {
					if(!q.empty() && d[id][v] < d[id][q.front()]) q.push_front(v);
					else q.push_back(v);
					inq[v] = 1;
				}
			}
		}
	}
}

inline int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(register int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x=f[x][i];
	if(x == y) return x;
	for(register int i = 19; i >= 0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}


signed main() {
	n = get(), m = get();
	for(register int i = 1; i <= m; i++) {
		int u = get(), v = get(), w = get();
		insedge(u, v, w);
	}
	dfs(1, 0, 0);
	for(register int i = 2; i <= k; i++) {
		if(!tree[i]) {
			if(!ins[edge[i].u]) tren[++top] = edge[i].u, ins[edge[i].u] = 1;
			if(!ins[edge[i].v]) tren[++top] = edge[i].v, ins[edge[i].v] = 1;
		}
	}
	for(register int i = 1; i <= top; i++) slf_spfa(tren[i], i);
	ask = get();
	for(register int i = 1; i <= ask; i++) {
		int u, v;
		u = get(), v = get();
		int x = lca(u, v);
		long long ans = dis[u] + dis[v] - dis[x] * 2;
		for(int i = 1; i <= top; i++) ans = min(ans, d[i][u] + d[i][v]);
		printf("%lld\n", ans);
	}
	return 0;
}