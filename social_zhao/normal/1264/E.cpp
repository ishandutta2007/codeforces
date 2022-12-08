#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105, S = N * N * 5, inf = 0x3f3f3f3f;
int n, m, rev[N][N], vis[N][N], ans[N][N], node;
int deg[S], s, t;
struct Edge { int v, nxt, f, c; } edge[N * N * 5];
int head[S], tot = 1;

void addedge(int u, int v, int f, int c) { edge[++tot] = (Edge){ v, head[u], f, c }, head[u] = tot; }
void insedge(int u, int v, int f, int c) { addedge(u, v, f, c), addedge(v, u, 0, -c); }

int dis[S], inq[S], flow[S], cur[S];
int q[S * 200], l, r;
bool spfa(){
	int i;
	for(i = 0; i <= t; ++i) cur[i] = head[i], dis[i] = inf;
	dis[s] = 0;
    l = 20001, r = 20000, q[++r] = s, inq[s] = 1;
	while(l <= r) {
		if(dis[q[l]] < dis[q[r]]) swap(q[l], q[r]);
		int u = q[l++]; inq[u] = 0;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(edge[i].f && dis[u] + edge[i].c < dis[v]) {
				dis[v] = dis[u] + edge[i].c;
				if(!inq[v]) {
					inq[v] = 1;
					if(l <= r && dis[v] < dis[q[l]]) q[--l] = v;
					else q[++r] = v;
				}
			}
		} 
	}
	return dis[t] < inf;
}

int dfs(int u,int a) {
	if(u == t || !a)return a;
	int flow=0, d, v;
	inq[u] = 1;
	for(int &i = cur[u]; i; i = edge[i].nxt) {
		v = edge[i].v;
		if(dis[u] + edge[i].c == dis[v] && !inq[v] && ((d = dfs(v, min(a, edge[i].f))) > 0)) {
			flow += d, a -= d, edge[i].f -= d, edge[i ^ 1].f += d;
			if(!a)break;
		}
	}
	inq[u] = 0;
	if(!flow) dis[u] = inf;
	return flow;
}

int zkw(){
	int maxflow = 0, flow;
	while(spfa())
        maxflow += dfs(s, inf);
	return maxflow;
}

int main() {
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) {
		u = get(), v = get();
		vis[u][v] = vis[v][u] = 1, ++deg[u], ans[u][v] = 1;
	}
	node = n, s = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(vis[i][j]) continue;
			rev[i][j] = ++node;
			insedge(s, node, 1, 0);
			insedge(node, i, 1, 0);
			insedge(node, j, 1, 0);
		}
	}
//	cout << node << " " << tot << endl;
	t = node + 1;
	for(int i = 1; i <= n; i++) {
		for(int j = deg[i] + 1; j <= n - 1; j++)
			insedge(i, t, 1, j * j - (j - 1) * (j - 1));
	}
	zkw();
//	cout << MaxFlow << " " << MinCost << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(vis[i][j]) continue;
			int u = rev[i][j];
			for(int k = head[u]; k; k = edge[k].nxt) {
				int v = edge[k].v;
				if(v <= n && !edge[k].f) ans[v][i + j - v] = 1;
			}
		}
	} 
	for(int i = 1; i <= n; i++, cout << endl)
		for(int j = 1; j <= n; j++)
			cout << ans[i][j];
	return 0;
}