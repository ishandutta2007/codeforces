#include <bits/stdc++.h>

using namespace std;

int rd() {
	char c = getchar(); int x = 0, f = 1;
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void wt(int x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int N = 2e5 + 10;

set <int> s[N];
struct edge {
	int nxt, to;
} e[N << 1];
int head[N], a[N], n, cnt;

void add_edge(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int p, int g) {
	set <int> :: iterator it;
	for (it = s[p].begin(); it != s[p].end(); it ++) s[u].insert(__gcd(*it, a[u]));
	s[u].insert(g), g = __gcd(g, a[u]), s[u].insert(g);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == p) continue;
		dfs(v, u, g);
	}
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <  n; i ++) {
		int u = rd(), v = rd();
		add_edge(u, v), add_edge(v, u);
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i ++) wt(*s[i].rbegin()), putchar(32);
	return 0;
}