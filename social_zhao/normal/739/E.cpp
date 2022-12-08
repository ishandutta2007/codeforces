#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-8;
int n, a, b, A, B, S, T, inq[N], flow[N], pre[N];
double p1[N], p2[N], dis[N], MaxCost;
struct Edge {
	int v, nxt, f;
	double c;
} edge[N];
int head[N], tot = 1;

void addedge(int u, int v, int f, double c) {
	edge[++tot].nxt = head[u];
	edge[tot].v = v;
	edge[tot].f = f;
	edge[tot].c = c;
	head[u] = tot;
}

void insedge(int u, int v, int f, double c) {
	addedge(u, v, f, c), addedge(v, u, 0, -c);
}

bool SPFA() {
	queue<int> q; q.push(S), inq[S] = 1;
	for(int i = 1; i <= T; i++) dis[i] = -0x3f3f3f3f; dis[S] = 0;
	flow[S] = 0x3f3f3f3f, flow[T] = 0;
	while(q.size()) {
		int u = q.front(); q.pop(); inq[u] = 0;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(!edge[i].f || dis[v] - dis[u] - edge[i].c >= -eps) continue;
			dis[v] = dis[u] + edge[i].c;
			flow[v] = min(flow[u], edge[i].f), pre[v] = i;
			if(!inq[v]) q.push(v), inq[v] = 1;
		}
	}
	return flow[T];
}

void update() {
	for(int i = T; i != S; i = edge[pre[i] ^ 1].v) 
		edge[pre[i]].f -= flow[T], edge[pre[i] ^ 1].f += flow[T], MaxCost += flow[T] * edge[pre[i]].c;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	A = n + 1, B = A + 1, S = B + 1, T = S + 1;
	insedge(S, A, a, 0), insedge(S, B, b, 0);
	for(int i = 1; i <= n; i++) scanf("%lf", &p1[i]), insedge(A, i, 1, p1[i]);
	for(int i = 1; i <= n; i++) scanf("%lf", &p2[i]), insedge(B, i, 1, p2[i]);
	for(int i = 1; i <= n; i++) insedge(i, T, 1, 0), insedge(i, T, 1, -p1[i] * p2[i]);
	while(SPFA())
		update();
	printf("%.8lf", MaxCost);
	return 0;
}