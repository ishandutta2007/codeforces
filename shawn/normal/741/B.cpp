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

const int maxn = 2e5;

int fa[maxn], w[maxn], d[maxn], n, m, W, f[maxn];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector <int> g[maxn];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi(), W = rdi();
	For(i, 1, n) w[i] = rdi(), fa[i] = i;
	For(i, 1, n) d[i] = rdi();
	For(i, 1, m) {
		int u = rdi(), v = rdi();
		int fu = find(u), fv = find(v);
		if (fu != fv) fa[fu] = fv;
	}
	For(i, 1, n) {
		int u = find(i);
		g[u].push_back(i);
	}
	For(i, 1, n) {
		if (find(i) != i) continue;
		Rep(j, W, 0) {
			pii sum;
			sum.fi = sum.se = 0;
			int siz = g[i].size();
			For(k, 0, siz - 1){
				sum.fi += w[g[i][k]];
				sum.se += d[g[i][k]];
				if (j >= w[g[i][k]]) f[j] = max(f[j], f[j - w[g[i][k]]] + d[g[i][k]]);
			}
			if (j >= sum.fi) f[j] = max(f[j], f[j - sum.fi] + sum.second);
		}
	}
	write(f[W]);
	return 0;
}

/*

*/