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

const int maxn = 160000;

struct Edge{
	int nxt, to;
}e[maxn << 1];
int head[maxn], siz[maxn], id[maxn], deg[maxn], cnt, n, m, cn;

void insert(int u, int v) {
	e[++cn].nxt = head[u], e[head[u] = cn].to = v, deg[v]++;
}

void dfs(int u, int p) {
	id[u] = cnt;
	siz[cnt]++;
	Edge(i, u) {
		int v = e[i].to;
		if (v == p || id[v]) continue;
		dfs(v, u);	
	} 
}

bool check() {
	For(i, 1, n) {
		if (siz[id[i]] - 1 != deg[i]) return 0;
	}	
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, m) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	}
	For(i, 1, n) if (!id[i]) cnt++, dfs(i, 0);
	if (check()) puts("YES"); else puts("NO");
	return 0;
}