#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, vis[N];
char opt[N];
vector<int> adj[N];
stack<int> s;
int dfn[N], low[N], tim, ins[N], col[N], cnt, sum[N], flag, mx[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void True() { printf("TRUE\n"); }
void False() { printf("FALSE\n"); }

void clear() {
	for(int i = 1; i <= n + n; i++) {
		head[i] = vis[i] = low[i] = dfn[i] = ins[i] = col[i] = sum[i] = mx[i] = 0;
		adj[i].clear();
	}
	tot = 0, tim = 0, cnt = 0, flag = 1;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim, ins[u] = 1, s.push(u);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		++cnt;
		while(s.top() != u) col[s.top()] = cnt, ins[s.top()] = 0, s.pop();
		col[u] = cnt, ins[u] = 0, s.pop();
	}
}

void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1; int nxt = 0;
	for(auto v : adj[u]) dfs(v), nxt += sum[v], mx[u] = max(mx[u], mx[v]);
	if(sum[u] && nxt) flag = 0;
	sum[u] += nxt;
}

void solve() {
	clear();
	n = get(), m = get();
	scanf("%s", opt + 1);
	for(int i = 1; i <= m; i++) {
		int ax = get(), ay = get();
		int x = abs(ax), y = abs(ay);
		if(ax > 0 && ay > 0) add(x + n, y), add(y + n, x);
		if(ax > 0 && ay < 0) add(x + n, y + n), add(y, x);
		if(ax < 0 && ay > 0) add(x, y), add(y + n, x + n);
		if(ax < 0 && ay < 0) add(x, y + n), add(y, x + n);
	}
	for(int i = 1; i <= n + n; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= n; i++) if(col[i] == col[i + n]) return False();
	for(int i = 1; i <= n; i++) {
		sum[col[i]] += opt[i] == 'A', sum[col[i + n]] += opt[i] == 'A';
		if(opt[i] == 'A') 
			mx[col[i]] = max(mx[col[i]], i), mx[col[i + n]] = max(mx[col[i + n]], i);
	}
	for(int i = 1; i <= cnt; i++) if(sum[i] > 1) return False();
	
	for(int u = 1; u <= n + n; u++)
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(col[u] == col[v]) continue;
			adj[col[u]].emplace_back(col[v]);
		}
	flag = 1;
	for(int i = 1; i <= cnt; i++) if(!vis[i]) dfs(i);
	if(!flag) return False();
	for(int i = 1; i <= n; i++) if(opt[i] == 'E')
		if(mx[col[i]] > i && mx[col[i + n]] > i) return False();
	return True();
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2 2
EA
1 -2
-1 2
*/