#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e3 + 5, P = 1e9 + 7;
int d, n, a[N], b[N], len, mn, ans;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int vis[N], f[N][2], g[2];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void inc(int &x, int y) { x = (x + y) % P; }

void dfs(int u, int lst) {
	f[u][a[u] == mn] = 1, vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst || a[v] < mn || a[v] > mn + d) continue;
		dfs(v, u);
		g[0] = g[1] = 0;
		for(int a = 0; a < 2; a++)
			for(int b = 0; b < 2; b++)
				inc(g[a | b], f[u][a] * f[v][b]);
		inc(f[u][0], g[0]), inc(f[u][1], g[1]);
	}
	inc(ans, f[u][1]);
}

void solve() {
	for(int i = 1; i <= n; i++) vis[i] = f[i][0] = f[i][1] = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] >= mn && a[i] <= mn + d && !vis[i]) dfs(i, 0);
}

signed main() {
	d = get(), n = get();
	for(int i = 1; i <= n; i++) a[i] = b[i] = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	sort(b + 1, b + 1 + n), len = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= len; i++) {
		mn = b[i];
		solve();
	}
	cout << ans;
	return 0;
}