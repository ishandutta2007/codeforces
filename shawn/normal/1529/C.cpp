#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 4e5 + 10;
int cnt, head[N];
struct Edge{
	int v, nxt;
}e[N];

int l[N], r[N];
long long f[N][2];

void add_edge(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].v = v;
}

void setup() {
	cnt = 0;
	memset(head, 0, sizeof head);
	memset(f, 0, sizeof f);
}

// f[i][0] vertice i choose l[i]
// f[i][1] vertice i choose r[i]

void dfs(int u, int fa) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
		f[u][0] = f[u][0] + max(f[v][1] + abs(l[u] - r[v]), f[v][0] + abs(l[u] - l[v]));
		f[u][1] = f[u][1] + max(f[v][0] + abs(l[v] - r[u]), f[v][1] + abs(r[u] - r[v]));
	}
}

void solve() {
	int n = rd();
	setup();
	for (int i = 1; i <= n; i ++) l[i] = rd(), r[i] = rd();
	for (int i = 1; i < n; i ++) {
		int u, v;
		u = rd(), v = rd();
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1, 0);
	printf("%lld\n", max(f[1][0], f[1][1]));
}

int main() {
	for (int t = rd(); t; t --) solve();
	return 0;
}