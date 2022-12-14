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
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
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

const int maxn = 1e6 + 10;

struct edge {
	int nxt, to;
}e[maxn << 1];
int head[maxn], cnt;
int siz[maxn], n, fa[maxn], val[maxn], rt, p1, p2, sum;

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v; 
}

void Dfs(int u) {
	siz[u] = val[u];
	Edge(i, u) {
		int v = e[i].to;
		Dfs(v);
		siz[u] += siz[v];
	}
	if (p1 && p2) return;
	if (u == rt) return; 
	if (siz[u] == sum) {
		!p1 ? p1 = u : p2 = u;
		siz[u] = 0;
	}
} 

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) {
		fa[i] = rdi(), val[i] = rdi();
		if (fa[i] == 0) rt = i;
		else insert(fa[i], i);
		sum += val[i]; 
	}
	if (sum % 3 != 0) return puts("-1"), 0;
	sum /= 3;
	Dfs(rt);
	if (p1 && p2) printf("%d %d", p1, p2);
	else puts("-1"); 
	return 0; 
}