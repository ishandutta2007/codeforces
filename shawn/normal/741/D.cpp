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

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a + 1)
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

const int maxn = 5e5 + 10;

struct edge {
	int nxt, to;
}e[maxn << 1];

int siz[maxn], st[maxn], ft[maxn], ver[maxn], dep[maxn], staus[maxn], head[maxn];
int f[1 << 22], son[maxn], ans[maxn], letter[maxn];
int n, T, cnt;

void before_dfs(int u) {
	siz[u] = 1;
	st[u] = ++ T;
	ver[T] = u;
	Edge(i, u) {
		int v = e[i].to;
		staus[v] = staus[u] ^ letter[v];
		dep[v] = dep[u] + 1;
		
		before_dfs(v);
		
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
	ft[u] = T;
}

void update(int u, int ver) {
	For(i, 0 , 21) {
		ans[u] = max(ans[u], f[staus[ver] ^ (1 << i)] + dep[ver] - dep[u] * 2);
	}
	ans[u] = max(ans[u], f[staus[ver]] + dep[ver] - dep[u] * 2);
}

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, bool keep) {
	Edge(i, u) {
		int v = e[i].to;
		if (v == son[u]) continue;
		dfs(v, 0);
	}
	if (son[u]) dfs(son[u], 1);
	
	ans[u] = max(ans[u], ans[son[u]]);
	Edge(i, u) {
		int v = e[i].to;
		if (v == son[u]) continue;
		ans[u] = max(ans[u], ans[v]);
		For(j, st[v], ft[v]) {
			update(u, ver[j]);		
		}
		For(j, st[v], ft[v]) f[staus[ver[j]]] = max(f[staus[ver[j]]], dep[ver[j]]);
	}
	update(u, u);
	f[staus[u]] = max(f[staus[u]], dep[u]);
	if (!keep) {
		For(i, st[u], ft[u])
			f[staus[ver[i]]] = -inf;
	}
	
}

int get() {
	char c = getchar(); 
	while (c < 'a') c = getchar(); 
	return c;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 2, n) {
		insert(rdi(), i);
		letter[i] = 1 << (get() - 'a');
	}
	memset(f, -0x7f7f, sizeof f);
	before_dfs(1);
	dfs(1, 0);
	For(i, 1, n) write(ans[i]), putchar(32);
	return 0;
}

/*

*/