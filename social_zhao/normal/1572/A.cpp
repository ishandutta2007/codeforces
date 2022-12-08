#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n;
struct Edge { int v, nxt; } edge[N];
int head[N], tot, top, f[N], deg[N];
priority_queue<int> q;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, deg[v]++; }

void clear(int n) {
	for(int i = 0; i <= n; i++) 
		head[i] = 0, tot = 0, f[i] = 0, deg[i] = 0;
	top = 0;
}

void solve() {
	n = get();
	clear(n);
	for(int i = 1; i <= n; i++) {
		int t = get();
		for(int j = 1, v; j <= t; j++) v = get(), add(v, i);
	}
	for(int i = 1; i <= n; i++) if(!deg[i]) q.push(-i), f[i] = 1;
	while(q.size()) {
		int u = -q.top(); q.pop(), ++top;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			f[v] = max(f[v], f[u] + (u > v));
			deg[v]--;
			if(!deg[v]) q.push(-v);
		}
	}
	if(top != n) printf("-1\n");
	else {
		int ans = 0;
		for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
		printf("%d\n", ans);
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
5
1 2
1 3
1 4
1 5
0
*/