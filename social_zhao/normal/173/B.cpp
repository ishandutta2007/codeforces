#include<bits/stdc++.h>
#define H(i) (i)
#define L(i) (i + n)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e6 + 5;
int n, m, vis[N], dis[N];
struct Edge {
	int v, nxt, w;
} edge[N];
int head[N], tot = 1;
char opt[N];
priority_queue<pair<int, int> > q;

void addedge(int u, int v, int w) {
	edge[++tot].v = v, edge[tot].w = w, edge[tot].nxt = head[u], head[u] = tot;
}

void insedge(int u, int v, int w) {
	addedge(u, v, w), addedge(v, u, w);
}

void Dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis)), dis[s] = 0;
	q.push(make_pair(0, s));
	while(q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(dis[u] + w < dis[v]) dis[v] = dis[u] + w, q.push(make_pair(-dis[v], v));
		}
	}
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", opt + 1);
		for(int j = 1; j <= m; j++) if(opt[j] == '#') insedge(H(i), L(j), 1);
	}
	Dijkstra(H(n));
	printf("%d\n", dis[H(1)] == 0x3f3f3f3f? -1 : dis[H(1)]);
	return 0;
}