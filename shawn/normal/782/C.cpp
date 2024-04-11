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

const int N = 2e5 + 10;
int c, head[N], ans[N], n, tot;
struct edge {
	int nxt, to;
}e[N << 1];
 
void insert(int u, int v) {
	e[++c].nxt = head[u], e[head[u] = c].to = v;
}

void dfs(int u, int p) {
	int cnt = 1;
	Edge(i, u) {
		int v = e[i].to;
		if (v == p) continue;
		while (cnt == ans[p] || cnt == ans[u]) cnt++;
		ans[v] = cnt++;
	}
	Edge(i, u) {
		int v = e[i].to;
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 2, n) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	}
	dfs(ans[1] = 1, 0);
	For(i, 1, n) tot = max(tot, ans[i]);
	write(tot), putchar(10);
	For(i, 1, n) write(ans[i]), putchar(32);
	return 0;
}