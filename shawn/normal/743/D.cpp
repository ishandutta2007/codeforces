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

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1000000000000000;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define Edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; int f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0){
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 2e5 + 10;

struct edge {
	int nxt, to;
}e[maxn << 1];

int head[maxn], cnt, n, a[maxn	];
ll ans, sum[maxn], f[maxn];

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int p) {
	sum[u] = a[u];
	int son = 0;
	f[u] = -inf;
	Edge(i, u) {
		int v = e[i].to;
		if (v == p) continue;
		dfs(v, u);
		son ++;
		sum[u] += sum[v];
		if (son > 1) {
			ans = max(ans, f[u] + f[v]);
		}
		f[u] = max(f[u], f[v]);
	}
	f[u] = max(f[u], sum[u]);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	ans = -inf;
	For(i, 1, n) a[i] = rdi();
	For(i, 1, n - 1) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	}
	dfs(1, 0);
	if (ans == -inf) puts("Impossible");
	else write(ans);
	return 0;
}

/*

*/