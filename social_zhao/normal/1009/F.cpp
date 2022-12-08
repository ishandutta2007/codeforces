#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int len[N], son[N];
int *f[N], *g[N], npool[N], *top = npool, ans[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int fa) {
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u), son[u] = len[v] >= len[son[u]]? v : son[u];
	}
	len[u] = len[son[u]] + 1;
}

void df5(int u, int fa) {
	f[u][0] = 1;
	if(son[u]) f[son[u]] = f[u] + 1, df5(son[u], u), ans[u] = ans[son[u]] + 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa || v == son[u]) continue;
		f[v] = top, top += len[v], df5(v, u);
		for(int j = 1; j <= len[v]; j++) {
			f[u][j] += f[v][j - 1];
			if(f[u][j] > f[u][ans[u]] || (f[u][j] == f[u][ans[u]] && j < ans[u])) ans[u] = j;
		}
	}
	if(f[u][ans[u]] == 1) ans[u] = 0;
}

int main() {
	n = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	f[1] = top, top += len[1];
	df5(1, 0);
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}