#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5, oo = 0x3f3f3f3f;
int n, m, g, a[N], b[N];
int s, t, ans, d[N], MaxFlow;
struct Edge { int v, nxt, f; } edge[N];
int head[N], tot = 1;

void add(int u, int v, int f) { edge[++tot] = (Edge){v, head[u], f}; head[u] = tot; }
void ins(int u, int v, int f) { add(u, v, f), add(v, u, 0); }

bool bfs() {
	memset(d, 0, sizeof(d));
	queue<int> q;
	d[t] = n + m + 1, q.push(t);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, f = edge[i ^ 1].f;
			if(d[v] || !f) continue;
			q.push(v), d[v] = d[u] - 1;
			if(v == s) return 1;
		}
	}
	return 0;
}

int dfs(int u, int flow) {
	if(u == t) return flow;
	int rest = flow;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, f = edge[i].f;
		if(!rest) break;
		if(d[v] != d[u] + 1 || !f) continue;
		int x = dfs(v, min(f, rest));
		if(!x) d[v] = 0;
		else edge[i].f -= x, edge[i ^ 1].f += x, rest -= x;
	}
	return flow - rest;
}

int main() {
	n = get(), m = get(), g = get(), s = 0, t = n + m + 1;
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get(), a[i]? ins(i, t, b[i]) : ins(s, i, b[i]);
	for(int i = 1; i <= m; i++) {
		int type = get(), w = get(), k = get();
		ans += w;
		if(type == 0) for(int j = 1, v; j <= k; j++) v = get(), ins(n + i, v, oo);
		if(type == 1) for(int j = 1, v; j <= k; j++) v = get(), ins(v, n + i, oo);
		if(get()) w += g;
		type == 0? ins(s, n + i, w) : ins(n + i, t, w); 
	}
	while(bfs())
		MaxFlow += dfs(s, oo);
	printf("%d\n", ans - MaxFlow);
	return 0;
}