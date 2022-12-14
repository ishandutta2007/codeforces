#include <bits/stdc++.h>

/*
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
*/

using namespace std;

typedef long long LL;
typedef double DB;
typedef unsigned int UI;
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define Edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0;
	int f = 1;
	char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) {
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 5050;
int n, m, ff, ch, En, head[N], c[N], d[N], sz[N], x[N], f[N][N][2];
struct edge { int to, nxt; } E[N];

void add_edge(int x, int y) {
	E[++En].to = y, E[En].nxt = head[x], head[x] = En;
}
void add(int &x, int y) {
	if (y > m) y = m + 1;
	if (y < x) x = y;
}
void dfs(int x) {
	sz[x] = 1, f[x][0][0] = f[x][0][1] = 0, f[x][1][0] = c[x];
	for (int k = head[x]; k; k = E[k].nxt) {
		dfs(E[k].to);
		for (int i = sz[x]; i >= 0; i --)
			for (int j = 1; j <= sz[E[k].to]; j++) {
				add(f[x][i + j][0], f[x][i][0] + f[E[k].to][j][0]);
				add(f[x][i + j][1], f[x][i][1] + f[E[k].to][j][0]);
				add(f[x][i + j][1], f[x][i][1] + f[E[k].to][j][1]);
			}
		sz[x] += sz[E[k].to];
	}
	for (int i = sz[x]; i; i --) {
		int t = f[x][i - 1][1] + d[x];
		if (t > m) t = m + 1;
		f[x][i][1] = t;
		add(f[x][i][1], f[x][i][0]);
	}
	f[x][0][1] = 0;
}
int main() {
	memset(f, 0x3f, sizeof f);
	n = rdi(), m = rdi();
	for (int i = 1; i <= n; i++) {
		c[i] = rdi(), d[i] = rdi();
		d[i] = c[i] - d[i];
		if (i != 1) x[i] = rdi(), add_edge(x[i], i);
	}
	dfs(1);
	int i;
	for (i = n; i >= 0; i --) if (f[1][i][1] <= m) break;
	printf("%d\n", i);
	return 0;

}