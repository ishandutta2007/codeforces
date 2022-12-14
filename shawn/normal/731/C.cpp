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

const int maxn = 2e5 + 10;

int fa[maxn], col[maxn], ans, n, m, k;
vector <int> c[maxn];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int l, int r){
	int fl = find(l), fr = find(r);
	if (fl != fr) fa[fl] = fr;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi(), k = rdi();
	For(i, 1, n) col[fa[i] = i] = rdi();
	For(i, 1, m) {
		int l = rdi(), r = rdi();
		merge(l, r);
	}
	For(i, 1, n) {
		c[find(i)].push_back(col[i]);
	}
	For(i, 1, n) {
		if (c[i].size() <= 1) continue;
		int siz = 0, mx = 0;
		map<int, int> Mp;
		For(j, 0, c[i].size() - 1) {
			Mp[c[i][j]] ++;
			mx = max(mx, Mp[c[i][j]]);
			siz ++;
		}
		ans += siz - mx;
	}
	write(ans);
	return 0;
}

/*

*/