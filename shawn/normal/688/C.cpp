#include <bits/stdc++.h>

using namespace std;

int read(){
	int x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e5 + 10;

int head[maxn], n, m, cnt, col[maxn];

bool F;

struct edge {
	int nxt, to;
}e[maxn << 1];

void insert(int u, int v) {
	e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

vector <int> s[2];

void dfs(int u, int c) {
	if (!F) return;
	if (col[u] != -1) {
		if (col[u] != c) F = 0;
		return;
	}
	col[u] = c;
	s[c].push_back(u);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dfs(v, c ^ 1);
	}
}

void print(vector <int> &a) {
	int siz = a.size();
	printf("%d\n", siz);
	for (int i = 0; i < siz; i ++) printf("%d ", a[i]);
	puts("");
}

int main() {
	n = read(), m = read();
	F = 1;
	for (int i = 1; i <= m; i ++) {
		int u = read(), v = read();
		insert(u, v), insert(v, u);
	}
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; i ++) {
		if (col[i] == -1) dfs(i, 0);
	}
	if (!F) puts("-1");
	else for (int i = 0; i < 2; i ++) print(s[i]);
	return 0;
}