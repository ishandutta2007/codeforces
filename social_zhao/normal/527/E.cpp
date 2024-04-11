#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, m, top, now;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot = 1, deg[N], bin[N], vis[N << 1];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, deg[v]++; }

void dfs(int u) {
	for(int &i = head[u]; i; i = edge[i].nxt) {
		if(vis[i] || vis[i ^ 1]) continue;
		int v = edge[i].v;
		vis[i] = 1;
		dfs(v);
		now ^= 1;
		if(now) printf("%d %d\n", u, v);
		else printf("%d %d\n", v, u);
	}
}

int main() {
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u);
	for(int i = 1; i <= n; i++) if(deg[i] & 1) bin[++top] = i;
	for(int i = 1; i < top; i += 2) ++m, add(bin[i], bin[i + 1]), add(bin[i + 1], bin[i]);
	if(m & 1) ++m, add(1, 1);
	top = 0;
	printf("%d\n", m);
	for(int i = 1; i <= top; i++) printf("%d %d\n", bin[i], bin[i]);
	dfs(1);
	return 0;
}