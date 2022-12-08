#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, mp, a[N];
struct Edge { int v, nxt, w; } edge[N << 1];
int head[N], tot;
int vis[N], mid, mx[N], node, sze[N];
double ans = 1e50, sd[N], sum[N];

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

void GetMid(int u, int lst) {
	sze[u] = 1, mx[u] = 0;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst || vis[v]) continue;
		GetMid(v, u), sze[u] += sze[v], mx[u] = max(mx[u], sze[v]);
	}
	mx[u] = max(mx[u], node - sze[u]);
	if(mx[u] <= mx[mid]) mid = u;
}

void dfs(int u, int lst, int dis) {
	sum[u] = a[u] * sqrt(dis) * sqrt(dis) * sqrt(dis), sd[u] = a[u] * sqrt(dis);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w;
		if(v == lst) continue;
		dfs(v, u, dis + w), sd[u] += sd[v], sum[u] += sum[v], sze[u] += sze[v];
	}
}

void GetSize(int u, int lst) {
	sze[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst || vis[v]) continue;
		GetSize(v, u), sze[u] += sze[v];
	}
}

void solve(int u) {
	vis[u] = 1;
	dfs(u, 0, 0);
	if(sum[u] < ans) ans = sum[u], mp = u;
	int son = 0; double mn = 1e50;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(vis[v]) continue; 
		if(sd[u] - 2 * sd[v] < mn) mn = sd[u] - 2 * sd[v], son = v;
	}
	if(son) GetSize(u, 0), node = sze[son], mid = 0, GetMid(son, u), solve(mid);
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1, u, v, w; i < n; i++) u = get(), v = get(), w = get(), add(u, v, w), add(v, u, w);
	mid = 0, mx[0] = 1e9, node = n, GetMid(1, 0), solve(mid);
	printf("%d %.10lf\n", mp, ans);
	return 0;
}