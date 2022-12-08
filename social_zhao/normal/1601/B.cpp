#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, M = N * 20;
int n, id[N], rt, node, lc[M], rc[M], suf[N], a[N], b[N], rev[M], pre[M]; 
struct Edge { int v, nxt, w; } edge[M];
int head[M], tot, dis[M], vis[M];
priority_queue<pair<int, int>> q;

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

int build(int l, int r) {
	int u = ++node;
	if(l == r) { id[l] = u, rev[u] = l + 1; return u; }
	int mid = (l + r) >> 1;
	lc[u] = build(l, mid), rc[u] = build(mid + 1, r);
	add(u, lc[u], 0), add(u, rc[u], 0);
	return u;
}

void update(int u, int l, int r, int a, int b, int st) {
	if(a == l && r == b) return add(st, u, 1);
	int mid = (l + r) >> 1;
	if(b <= mid) update(lc[u], l, mid, a, b, st);
	else if(a > mid) update(rc[u], mid + 1, r, a, b, st);
	else update(lc[u], l, mid, a, mid, st), update(rc[u], mid + 1, r, mid + 1, b, st);
}

void Dijkstra(int st) {
	memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis));
	dis[st] = 0, q.push({ 0, st });
	while(q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(dis[u] + w < dis[v]) 
				dis[v] = dis[u] + w, q.push({-dis[v], v}), pre[v] = u;
		} 
	}
}

void print(int u) {
	if(pre[u]) print(pre[u]);
	if(rev[u]) 
		cout << rev[u] - 1 << " ";
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	rt = build(0, n);
	for(int i = 1; i <= n; i++) suf[i] = ++node;
	for(int i = 1; i <= n; i++) 
		add(id[i], suf[i + b[i]], 0);
	for(int i = 1; i <= n; i++) 
		update(rt, 0, n, i - a[i], i, suf[i]);
	Dijkstra(suf[n]);
	if(dis[id[0]] == 0x3f3f3f3f) cout << -1 << endl;
	else {
		cout << dis[id[0]] << endl;
		print(id[0]);
	}
	return 0;
}