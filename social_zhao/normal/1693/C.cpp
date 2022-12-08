#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, deg[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int f[N], vis[N];
priority_queue<pair<int, int>> q;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, deg[v]++; }

int main() {
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(v, u);
	memset(f, 0x3f, sizeof(f));
	f[n] = 0, q.push(make_pair(0, n));
	while(q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			--deg[v];
			if(deg[v] + f[u] + 1 < f[v])
				f[v] = deg[v] + f[u] + 1, q.push(make_pair(-f[v], v));
		}
	}
	cout << f[1] << endl;
	return 0;
}