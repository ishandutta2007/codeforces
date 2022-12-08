#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, m, k, h[N], a[N], b[N];
struct Edge { int v, nxt; } edge[N];
int head[N], tot, f[N][20], dep[N], dfn[N], tim;
int imp[N], st[N], top;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1, f[u][0] = fa, dfn[u] = ++tim;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].v != fa) dfs(edge[i].v, u);
	head[u] = 0;
}

void dfs(int u) {
	a[u] = b[u] = 0; int sum = 0, sze = 0;
	for(int i = head[u]; i; i = edge[i].nxt) dfs(edge[i].v), sum += a[edge[i].v], sze += b[edge[i].v];
	if(imp[u]) b[u] = 1, a[u] = sum + sze;
	else {
		if(sze <= 1) b[u] = sze, a[u] = sum;
		else a[u] = sum + 1;
	}
	return head[u] = 0, void();
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

void clear() { for(int i = 1; i <= k; i++) imp[h[i]] = 0; }

void solve() {
	k = get();
	for(int i = 1; i <= k; i++) h[i] = get(), imp[h[i]] = 1;
	for(int i = 1; i <= k; i++) 
		if(imp[h[i]] && imp[f[h[i]][0]]) return printf("-1\n"), clear();
	sort(h + 1, h + 1 + k, [](int x, int y) { return dfn[x] < dfn[y]; });
	st[top = 1] = 1, tot = 0;
	for(int i = 1; i <= k; i++) {
		if(h[i] == 1) continue;
		int l = lca(h[i], st[top]);
		if(l != st[top]) {
			while(dfn[l] < dfn[st[top - 1]]) add(st[top - 1], st[top]), top--;
			if(dfn[l] == dfn[st[top - 1]]) add(st[top - 1], st[top]), top--;
			else add(l, st[top]), st[top] = l;
		} 
		st[++top] = h[i];
	}
	for(int i = 1; i < top; i++) add(st[i], st[i + 1]);
	dfs(1);
	printf("%d\n", a[1]), clear();
}

int main() {
	n = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0), m = get();
	for(int i = 1; i <= m; i++) solve();
	return 0;
}

/*
7
1 2
2 3
3 4
4 5
5 6
6 7
1
2 3 4
*/