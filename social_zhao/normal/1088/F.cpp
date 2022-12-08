#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, a[N], rt, f[N][20], dep[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
	f[u][0] = lst, dep[u] = dep[lst] + 1;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].v != lst) dfs(edge[i].v, u);
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	rt = 1;
	for(int i = 2; i <= n; i++) if(a[i] < a[rt]) rt = i;
	dfs(rt, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i == rt) continue;
		int mn = (ceil(log2(dep[i] - 1)) + 1) * a[rt] + a[i];
		for(int j = 0; j <= 19; j++) if(f[i][j]) mn = min(mn, (j + 1) * a[f[i][j]] + a[i]);
		ans += mn;
	}
	cout << ans;
	return 0;
}