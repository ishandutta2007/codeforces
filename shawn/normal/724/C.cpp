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
typedef pair<long long, long long> pii;

const long long inf = 0x7f7f7f7f;

#define rdi() read<long long>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define fi first
#define se second
#define For(i, j, k) for (long long i = j; i <= k; i ++)
#define Rep(i, j, k) for (long long i = j; i >= k; i --)
#define Edge(i, u) for (long long i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; long long f = 1; char c = getchar();
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

const long long maxn = 1e5 + 10;

long long vis[maxn << 1];
long long n, m, k, N, M;

long long cal(long long a, long long b) {
	long long t = ((-a - b) % M + M) % M;
	if (vis[t] == -1) return inf;
	return vis[t] * N + a;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi(), k = rdi();
	N = n << 1, M = m << 1;
	memset(vis, -1, sizeof vis);
	long long now = 0, cnt = 0;
	while (vis[now] == -1) {
		vis[now] = cnt ++;
		now += N, now %= M;
	}
	For(i, 1, k) {
		long long x = rdi(), y = rdi();
		long long t = min(min(cal(x, y), cal(x, -y)), min(cal(N - x, y), cal(N - x, -y)));
		if (t == inf) t = -1;
		write(t), putchar(10);
	}
	return 0;
}

/*

*/