#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, k, vis[N], sze[N], ans;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
	sze[u] = vis[u];
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u), sze[u] += sze[v], ans += min(sze[v], 2 * k - sze[v]);
	}
}

main() {
	n = get(), k = get();
	for(int i = 1; i <= k << 1; i++) vis[get()] = 1;
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	cout << ans;
	return 0;
}