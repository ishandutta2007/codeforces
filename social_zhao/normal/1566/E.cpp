#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, ans;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, f[N];

void clear(int n) {
	for(int i = 1; i <= n; i++) head[i] = f[i] = 0;
	tot = ans = 0;
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int fa) {
	int deg = 0;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u), deg += f[v]; 
	}
	if(!deg) f[u] = 1;
	else f[u] = 0;
	if(f[u] == 0) ans += deg - 1;
}

void solve() {
	n = get();
	clear(n);
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	printf("%d\n", ans + 1);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}