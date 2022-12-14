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
bool vis[N];
int path[N * 2], cnt, len, head[N], n, m, k, c;
struct egde{
	int nxt, to;
}e[N << 1];

void insert(int u, int v) {
	e[++c].nxt = head[u], e[head[u] = c].to = v;
}

void dfs(int u) {
	vis[u] = 1;
	path[++cnt] = u;
	Edge(i, u) {
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v);
		path[++cnt] = u;
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi(), k = rdi();
	For(i, 1, m) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	}
	dfs(1);
	int seq = (2 * n + k - 1) / k;
	For(i, 1, k) {
		len = min(seq, cnt);
		if (len == 0) {
			puts("1 1");
			continue;	
		}
		write(len), putchar(32);
		for (int j = 0; cnt && j < len; cnt --, j ++) write(path[cnt]), putchar(32);
		putchar(10);
	}
	return 0;
}