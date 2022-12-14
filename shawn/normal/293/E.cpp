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

const int maxn = 1e5 + 10;

struct edge {
	int nxt, to, w;
}e[maxn << 1];

int head[maxn], cnt;

void insert(int u, int v, int w) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v, e[cnt].w = w;
}

int siz[maxn], mx_siz[maxn], rt, sum;
bool vis[maxn];

int Q[maxn << 1];

void getrt(int u, int p) {
	siz[u] = 1, mx_siz[u] = 0;
//	write(u);
//	puts("");
	Edge(i, u) {
		int v = e[i].to;
		if (vis[v] || v == p) continue;
		getrt(v, u);
		mx_siz[u] = max(mx_siz[u], siz[v]);
		siz[u] += siz[v];
	}
	mx_siz[u] = max(mx_siz[u], sum - siz[u]);
	if (mx_siz[u] < mx_siz[rt]) rt = u;
}

int q[maxn << 1];

// path
pii p[maxn];
int nump, L;

int bit[maxn], mx = 0;

void Add(int x, int f) {
	for (int i = x; i <= mx; i += i & -i) {
		if (f == 0) bit[i] = 0;
		else bit[i] += f;	
	}
}

int Sum(int x) {
	int ret = 0;
	for (int i = x; i; i -= i & -i) ret += bit[i];
	return ret;
}

int fa[maxn], dep[maxn], dis[maxn];
int W;

ll calc(int u, int d, int w) {
	nump = 0;
	dep[u] = d;
	dis[u] = w;
	fa[u] = 0;
	int l = 0, r = 1;
	q[1] = u;
	while (l < r) {
		int now = q[++l];
		if (!vis[now] || u != now) p[++nump] = make_pair(dis[now], dep[now]); 
		Edge(j, now) {
			int v = e[j].to;
			if (vis[v] || fa[now] == v) continue;
			fa[v] = now;
			dep[v] = dep[now] + 1;
			dis[v] = dis[now] + e[j].w;
			q[++r] = v; 
		}
	}
	sort(p + 1, p + nump + 1);
	ll ret = 0;
	mx = 0;
	r = nump;
	For(i, 1, nump) mx = max(mx, p[i].second);
	For(i, 1, mx) bit[i] = 0;
	For(i, 1, nump) Add(p[i].se, 1);
	For(i, 1, r) {
		while (p[i].fi + p[r].fi > W && i < r) Add(p[r--].se, -1);
		if (i >= r) break;
		Add(p[i].se, -1);
		if (L - p[i].se > 0) ret += Sum(min(mx, L - p[i].se));
	}	
	return ret;
}

ll tot;

void divide(int u) {
	
	rt = 0;
	getrt(u, 0);	
	vis[rt] = 1;
	getrt(rt, 0);
//	write(rt);
//	puts("");
	
	tot += calc(rt, 0, 0);
	For(i, 1, nump) {
		if (p[i].fi > W) break;
		if (p[i].se <= L) tot++;
	}
	 
	Edge(i, rt) {
		int v = e[i].to;
		if (vis[v] || v == fa[rt]) continue;
		tot -= calc(v, 1, e[i].w);
	}
	
	Edge(i, rt) {
		int v = e[i].to;
		if (vis[v] || v == fa[rt]) continue;
		sum = siz[v];
		divide(v);
	}
}

int n;

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	sum = n = rdi(), L = rdi(), W = rdi();
	For(i, 2, n) {
		int p = rdi(), w = rdi();
		insert(p, i, w);
		insert(i, p, w);
	}
	mx_siz[0] = inf;
	divide(1);
	write(tot);
	return 0; 
}

/*

*/