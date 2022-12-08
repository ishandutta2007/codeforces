#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int M = 2e4 + 5, N = 805, oo = 0x3f3f3f3f;
int n, m, bin[N], now;
struct Edge { int v, nxt, f; } edge[M];
struct Link { int u, v, f; } lnk[N];
int head[N], cur[N], tot = 1, cnt;
int S, T, d[N];
int fa[N << 1], f[N << 1][20], dep[N << 2], st[N], top, val[N << 2];
vector<int> adj[N << 1];

void addedge(int u, int v, int f) { edge[++tot] = (Edge){ v, head[u], f }, head[u] = tot; }
void insedge(int u, int v, int f) { addedge(u, v, f), addedge(v, u, 0); }
void rebuild() { for(int i = 0; i <= tot; i += 2) edge[i].f += edge[i ^ 1].f, edge[i ^ 1].f = 0; }
int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

queue<int> q;
int bfs() {
	memset(d, 0, sizeof(d));
	for(int i = 1; i <= n; i++) cur[i] = head[i];
	while(q.size()) q.pop();
	q.push(S), d[S] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, f = edge[i].f;
			if(d[v] || !f) continue;
			d[v] = d[u] + 1, q.push(v);
		}
	}
	return d[T];
}

int dfs(int u, int flow) {
	if(u == T) return flow;
	int rest = flow;
	for(int &i = cur[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, f = edge[i].f;
		if(d[v] != d[u] + 1 || !f) continue;
		if(!rest) break;
		int t = dfs(v, min(rest, f));
		if(!t) d[v] = 0;
		else edge[i].f -= t, edge[i ^ 1].f += t, rest -= t;
	}
	return flow - rest;
}

int Dinic() {
	int res = 0;
	while(bfs()) res += dfs(S, +oo);
	return res;
}

void build(int l, int r) {
	if(l >= r) return;
	rebuild(), S = bin[l], T = bin[l + 1];
	int MinCut = Dinic();
	lnk[++cnt] = (Link){ S, T, MinCut };
	static int tmp1[N], tmp2[N], top1, top2;
	top1 = top2 = 0;
	for(int i = l; i <= r; i++)
		if(d[bin[i]]) tmp1[++top1] = bin[i];
		else tmp2[++top2] = bin[i];
	for(int i = 1; i <= top1; i++) bin[l + i - 1] = tmp1[i];
	for(int i = 1; i <= top2; i++) bin[l + top1 + i - 1] = tmp2[i];
	int mid = l + top1 - 1;
	build(l, mid), build(mid + 1, r);
}

void GetDfn(int u, int lst) {
	dep[u] = dep[lst] + 1, f[u][0] = lst;
	if(u <= n) st[++top] = u;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(auto v : adj[u]) GetDfn(v, u);
}

int GetLCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int main() {
	n = get(), m = get();
	for(int i = 1, u, v, f; i <= m; i++) 
		u = get(), v = get(), f = get(), insedge(u, v, f), insedge(v, u, f);
	for(int i = 1; i <= n; i++) 
		bin[i] = i;
	build(1, n);
	assert(cnt == n - 1);
	sort(lnk + 1, lnk + 1 + cnt, [](Link x, Link y){ return x.f > y.f; });
	for(int i = 1; i <= n * 2 - 1; i++) fa[i] = i;
	int node = n; 	
	for(int i = 1; i <= cnt; i++) {
		++node, val[node] = lnk[i].f;
		int x = find(lnk[i].u), y = find(lnk[i].v);
		adj[node].emplace_back(x), adj[node].emplace_back(y);
		fa[x] = fa[y] = node;
	}
	GetDfn(node, 0);
	int ans = 0;
	for(int i = 1; i <= top; i++) ans += val[GetLCA(st[i], st[i % top + 1])];
	for(int i = 1; i <= n; i++) st[i + n] = st[i];
	int mp = 1;
	for(int i = 2; i <= n; i++) if(val[GetLCA(st[i], st[i + 1])] < val[GetLCA(st[mp], st[mp + 1])]) mp = i;
	printf("%d\n", ans - val[GetLCA(st[mp], st[mp + 1])]);
	for(int i = mp + 1; i <= mp + n; i++) printf("%d ", st[i]);
	return 0;
}