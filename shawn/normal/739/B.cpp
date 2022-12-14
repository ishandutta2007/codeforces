#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

typedef long long ll;

const int maxn = 3e5 + 10, inf = 1ll << 60ll;

int head[maxn], cnt, a[maxn], ans[maxn], s[maxn], n;

struct edge {
	int nxt, to, w;
}e[maxn << 1];

ll dis[maxn];

void insert(int u, int v, int w) {
	e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v, e[cnt].w = w;
}

void dfs(int u, int fa, int dep, ll d) {
	s[dep] = u;
	dis[dep] = d;
	int pos = lower_bound(dis, dis + dep + 1, d - a[u]) - dis - 1;	
	ans[s[pos]] --;
	ans[u] ++;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v, u, dep + 1, d + e[i].w);
		ans[u] += ans[v];
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	for (int i = 2; i <= n; i ++) {
		int u = read(), w = read();
		insert(i ,u, w), insert(u, i, w);
	}
	dis[0] = -inf;
	dfs(1, 0, 1, 0);
	for (int i = 1; i <= n; i ++) printf("%d ", ans[i] - 1);
	return 0;
}