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

int n, cnt, u[maxn], v[maxn], head[maxn], col[maxn];

bool f;

void insert(int u, int v) {
	e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int c) {
	if (col[u]) return;
	col[u] = c;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dfs(v, 3 - c);
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) {
		u[i] = rdi(), v[i] = rdi();
		insert(u[i], v[i]), insert(v[i], u[i]); 
		insert(i * 2 - 1, i << 1), insert(i << 1, i * 2 - 1);
	}
	For(i, 1, 2 * n) if (col[i] == 0) dfs(i, 1);
	For(i, 1, n) write(col[u[i]]), putchar(32), write(col[v[i]]), puts("");
	return 0;
}

/*

*/