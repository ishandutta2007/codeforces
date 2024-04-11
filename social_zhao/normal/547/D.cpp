#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, _x[N], _y[N];
stack<int> binx[N], biny[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, col[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int c) {
	if(~col[u]) return;
	col[u] = c;
	for(int i = head[u]; i; i = edge[i].nxt) dfs(edge[i].v, c ^ 1);
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) _x[i] = get(), _y[i] = get(), binx[_x[i]].push(i), biny[_y[i]].push(i);
	for(int i = 1, u, v; i <= 2e5; i++) {
		while(binx[i].size() > 1) u = binx[i].top(), binx[i].pop(), v = binx[i].top(), binx[i].pop(), add(u, v), add(v, u);
		while(biny[i].size() > 1) u = biny[i].top(), biny[i].pop(), v = biny[i].top(), biny[i].pop(), add(u, v), add(v, u);
	}
	memset(col, -1, sizeof(col));
	for(int i = 1; i <= n; i++) dfs(i, 0);
	for(int i = 1; i <= n; i++) printf(col[i] == 1? "b" : "r");
	return 0;
}