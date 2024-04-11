#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, M = N * 16;
int n, m, s, offset;
struct Edge { int v, nxt, w; } edge[M * 8];
int head[N * 8], tot;
int pos[N];

void addedge(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)

void build(int u, int l, int r) {
	if(l == r) return pos[l] = u, void();
	addedge(u, lc, 0), addedge(u, rc, 0), addedge(lc + offset, u + offset, 0), addedge(rc + offset, u + offset, 0);
	build(lc, l, mid), build(rc, mid + 1, r);
}

void LinkDown(int u, int l, int r, int a, int b, int v, int w) {
	if(a == l && r == b) return addedge(v, u, w);
	if(b <= mid) LinkDown(lc, l, mid, a, b, v, w);
	else if(a > mid) LinkDown(rc, mid + 1, r, a, b, v, w);
	else LinkDown(lc, l, mid, a, mid, v, w), LinkDown(rc, mid + 1, r, mid + 1, b, v, w);
}

void LinkUp(int u, int l, int r, int a, int b, int v, int w) {
	if(a == l && r == b) return addedge(u + offset, v, w);
	if(b <= mid) LinkUp(lc, l, mid, a, b, v, w);
	else if(a > mid) LinkUp(rc, mid + 1, r, a, b, v, w);
	else LinkUp(lc, l, mid, a, mid, v, w), LinkUp(rc, mid + 1, r, mid + 1, b, v, w);
}

long long dis[N * 8];
int vis[N * 8];
priority_queue<pair<long long, int> > q;
void Dijkstra(int st) {
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0, q.push(make_pair(0, st));
	while(q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(dis[v] > dis[u] + w) dis[v] = dis[u] + w, q.push({ -dis[v], v });
		}
	}
}

int main() {
	n = get(), m = get(), s = get(), offset = 4 * n;
	build(1, 1, n);
	for(int i = 1; i <= n; i++) addedge(pos[i], pos[i] + offset, 0), addedge(pos[i] + offset, pos[i], 0);
	for(int i = 1; i <= m; i++) {
		int opt = get(), x, l, r, w;
		if(opt == 1) {
			x = get(), l = get(), w = get();
			addedge(pos[x], pos[l], w);
		}
		else if(opt == 2) {
			x = get(), l = get(), r = get(), w = get();
			LinkDown(1, 1, n, l, r, pos[x], w);
		}
		else {
			x = get(), l = get(), r = get(), w = get();
			LinkUp(1, 1, n, l, r, pos[x], w);
		}
	}
	Dijkstra(pos[s]);
	for(int i = 1; i <= n; i++) printf("%lld ", dis[pos[i]] == 0x3f3f3f3f3f3f3f3f? -1 : dis[pos[i]]);
	return 0;
}