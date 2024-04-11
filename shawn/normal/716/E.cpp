#pragma GCC optimize("O2")
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

int head[maxn], cnt;
int n, M;

struct edge {
	int nxt, to, w;
}e[maxn << 1];

void insert(int u, int v, int w) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v, e[cnt].w = w%M;
}

int siz[maxn], mx_siz[maxn], sum, rt;
bool vis[maxn];

void getrt(int u, int p) {
	siz[u] = 1, mx_siz[u] = 0;
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


map <int, int> Ma, Mb;
int q[maxn], mi[maxn];


int quick_power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = 1ll * ret * a % M;
		}
		a = 1ll * a * a  % M;
		b >>= 1;
	}
	return ret;
}

int A[maxn], B[maxn], dep[maxn], fa[maxn];
long long tot;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	exgcd(b, a % b, x, y);
	ll t = x;
	x = y, y = t - a / b * y;
}

void calc(int s) {
	Edge(k, s) {
		int v_ = e[k].to;
		if (vis[v_]) continue;
		A[v_] = e[k].w, B[v_] = e[k].w, dep[v_] = 1;
		fa[v_] = s;
		int l = 0, r = 1;
		q[1] = v_;
		while (l < r) {
			int u = q[++l];
			Edge(j, u) {
				int v = e[j].to;
				if (vis[v] || v == fa[u]) continue;
				fa[v] = u;
				dep[v] = dep[u] + 1;
				A[v] = (1ll * A[u] + (1ll * e[j].w * mi[dep[v] - 1] % M)) % M;
				B[v] = (1ll * B[u] * 10 + e[j].w) % M;
				q[++r] = v;
			}
		}
		For(i, 1, r) {
			ll y, inv;
			exgcd(mi[dep[q[i]]], M, inv, y); 
			int a = (1ll * (M - B[q[i]]) * inv % M + M) % M;
			tot += Ma[a];
			int b = (-A[q[i]] + M) % M;
			tot += Mb[b];
		}
		For(i, 1, r) {
			ll inv, y;
			exgcd(mi[dep[q[i]]], M, inv, y);
			Ma[A[q[i]]]++;
			Mb[(1ll * B[q[i]] * inv % M + M) % M]++;
		} 
	}
}

void divide(int u) {
	getrt(u, rt = 0);
	vis[rt] = 1;
	getrt(rt, 0);
	
	calc(rt); 
	tot += Ma[0] + Mb[0];
	Ma.clear(), Mb.clear();
	
	Edge(i, rt) {
		int v = e[i].to;
		if (vis[v]) continue;
		sum = siz[v];
		divide(v);
	}
}

int main() {
//	freopen("E.in", "r", stdin);
//	freopen("E.out", "w", stdout);
	sum = n = rdi(), M = rdi();
	For(i, 2, n) {
		int u = rdi() + 1, v = rdi() + 1, w = rdi();
		insert(u, v, w), insert(v, u, w);		
	}
	mx_siz[0] = inf;
	mi[0] = 1;
	For(i, 1, n) mi[i] = 1ll * mi[i - 1] * 10 % M;

	divide(1);
	write(tot);
	return 0;	
}

/*
10 999999937
1 0 9
2 1 9
3 2 9
4 3 9
5 4 9
6 5 9
7 6 9
8 7 3
9 8 7
*/