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
typedef pair<LL, LL> PII;

const LL inf = 1e18;

#define rdi() read<LL>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (LL i = j; i <= k; i ++)
#define Rep(i, j, k) for (LL i = j; i >= k; i --)
#define Edge(i, u) for (LL i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; LL f = 1; char c = getchar();
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

const LL maxn = 550;
LL n, m;
bool flag;
bitset <maxn> f[65][2][maxn], t, tt;
LL ans;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, m) {
		LL x = rdi(), y = rdi(), k = rdi();
		f[0][k][x][y] = 1;
	} 
	For(i, 1, 60) For(k, 1, n) For(j, 1, n) For(z, 0, 1) if (f[i - 1][z][j][k]) f[i][z][j] |= f[i - 1][z ^ 1][k];
	For(i, 1, n) if (f[60][0][1][i]) return puts("-1"), 0;
	LL i;
	for (tt[1] = 1, i = 59; i >= 0; i--) {
		LL j;
		for (t = 0, j = 1; j <= n; j++) {
			if (tt[j]) t |= f[i][flag][j];
		}
		if (t.count()) tt = t, ans += (1ll << i), flag ^= 1;
	}
	
	if (ans > inf) puts("-1");
	else write(ans);
	return 0;
}