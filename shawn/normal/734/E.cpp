#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const int maxn = 2e5 + 10, inf = 0x7f7f7f7f;

struct edge {
	int nxt, to;
}e[maxn << 1];

int n, head[maxn], c[maxn], ans, cnt, pt;

void insert(int u, int v){
	 e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int fa, int step) {
	if (step > ans) ans = step, pt = u;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v, u, step + (c[v] != c[u]));
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) c[i] = read();
	for (int i = 1; i < n; i ++) {
		int u = read(), v = read();
		insert(u, v), insert(v, u);
	}
	dfs(1, 0, 1);
	ans = 0;
	dfs(pt, 0, 1);
	printf("%d\n", ans >> 1);
	return 0;
}