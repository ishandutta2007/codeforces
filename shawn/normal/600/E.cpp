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

const int maxn = 2e5 + 10;

struct DFN{
	int st, ed;
}dfn[maxn];

struct edge {
	int nxt, to;
}e[maxn << 1];

ll ans[maxn];

int head[maxn], appear[maxn], col[maxn], siz[maxn], ver[maxn];
int cnt, T, n;

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void before_dfs(int u, int p) {
	siz[u] = 1;
	dfn[u].st = ++ T;
	ver[T] = u;
	Edge(i, u) {
		int v = e[i].to;
		if (v == p) continue;
		before_dfs(v, u);
		siz[u] += siz[v];
	}
	dfn[u].ed = T;
}

struct Dominating{
	ll sum, cnt;

	void clear(){
		sum = cnt = 0;
	}
	
}Dma;

void update(int ver) {
	if (++ appear[col[ver]] > Dma.cnt) Dma.cnt = appear[col[ver]], Dma.sum = col[ver];
	else if (appear[col[ver]] == Dma.cnt) Dma.sum += col[ver];
}

void dfs(int u, int p, int f){
	int mx = -1, heavy_son = -1;
	Edge(i, u) {
		int v = e[i].to;
		if (v == p) continue;
		if (siz[v] > mx) mx = siz[v], heavy_son = v;
	}
	Edge(i, u) {
		int v = e[i].to;
		if (v == p || v == heavy_son) continue;
		dfs(v, u, 0);	
	}
	if (heavy_son != -1) dfs(heavy_son, u, 1);
	
	
	Edge(i, u) { // count color of light_vertex
		int v = e[i].to;
		if (v == p || v == heavy_son) continue;
		For(j, dfn[v].st, dfn[v].ed) {
			update(ver[j]);
		}
	}
	update(u);
	ans[u] = Dma.sum;
	if (!f){
		Dma.clear();
		For(j, dfn[u].st, dfn[u].ed) {
			appear[col[ver[j]]] --;
		}
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) col[i] = rdi();
	For(i, 1, n - 1) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	} 
	before_dfs(1, 0);
	dfs(1, 0, 0);
	For(i, 1, n) write(ans[i]), putchar(32);
	return 0;
}

/*

*/