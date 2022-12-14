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

const int maxn = 5e5 + 10;

int cnt, T, n, m;
int siz[maxn], head[maxn], dep[maxn], let[maxn], val[maxn][30];

char a[maxn];
bool hea[maxn];

struct edge {
	int nxt, to;
}e[maxn << 1];

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void before_dfs(int u) {
	siz[u] = 1;
	Edge(i, u) {
		int v = e[i].to;
		dep[v] = dep[u] + 1;
		before_dfs(v);
		siz[u] += siz[v];
	}
}

vector < pii > ask[maxn];

void update(int ver) {
	let[dep[ver]] -= val[dep[ver]][a[ver] - 'a'];
	val[dep[ver]][a[ver] - 'a'] ^= 1;
	let[dep[ver]] += val[dep[ver]][a[ver] - 'a'];
	Edge(i, ver) {
		int v = e[i].to;
		if (hea[v]) continue;
		update(v);
	}
}

bool ans[maxn];

void dfs(int u, bool f) {
	int mx = 0, hs;
	Edge(i, u) {
		int v = e[i].to;
		if (siz[v] > mx) mx = siz[v], hs = v;
	}
	Edge(i, u) {
		int v = e[i].to;
		if (v != hs) dfs(v, 0);
	}
	if (mx) hea[hs] = 1, dfs(hs, 1);
	update(u);
	int ed = ask[u].size() - 1;
	For(i, 0, ed) 
		ans[ask[u][i].se] = (let[ask[u][i].fi] <= 1);
	if (mx) hea[hs] = 0;
	if (!f) update(u);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 2, n) insert(rdi(), i);
	rds(a);
	For(i, 1, m) {
		int v = rdi(), h = rdi();
		ask[v].push_back({h - 1, i});
	}
	
	before_dfs(1);
	dfs(1, 0);
	
	For(i, 1, m) puts(ans[i] ? "Yes" : "No");
	return 0;
}

/*

*/