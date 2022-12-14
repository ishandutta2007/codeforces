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

ll p[maxn], s[maxn], g[maxn], f[maxn], ans;
int n, c;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), c = rdi();
	For(i, 1, n) p[i] = rdl();
	For(i, 1, n) s[i] = rdl();
	For(i, 1, n) {
		f[0] = g[0] + p[i];
		For(j, 1, i - 1) {
			f[j] = min(g[j - 1] + s[i], g[j] + 1ll * j * c + p[i]);
		}
		f[i] = g[i - 1] + s[i];
		memcpy(g, f, sizeof f);
	}
	ans = 1e18;
	For(j, 0, n) {
		ans = min(ans, f[j]);
	}
	write(ans);
	return 0;
}

/*

*/