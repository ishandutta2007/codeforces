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

const int maxn = 3e5 + 10;

int cnt, a[maxn], n, k, need, last, run[maxn];
pii f[maxn];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), k = rdi();
	For(i, 1, n) {
		a[i] = rdi();
		if (a[i] < 0) need++, run[i] = 1;
	}
	if (need > k) return puts("-1"), 0;
//	ans = k * 2;
	For(i, 1, n) {
		if (a[i] < 0) {
			if (last) f[++cnt].se = last, f[cnt].fi = i - last + 1;
			last = i;
		}
	}
	//if (a[n] >= 0) f[++cnt].fi = n - last + 1, f[cnt].se = last;
	sort(f + 1, f + cnt + 1);
	k -= need;
	For(i, 1, cnt) {
		if (k >= (f[i].fi - 2)) {
			k -= (f[i].fi - 2);
			For(j, f[i].se, f[i].se + f[i].fi - 1) run[j] = 1;
		}else break;
	}
	if (k > 0 && a[n] >= 0 && need) {
		if (k >= (n - last - 2)) For(i, last, n) run[i] = 1;
	}
	int ans = 0, now = 0;
		For(i, 1, n) {
		if (run[i] != now) ans ++, now ^= 1;
	}
	write(ans);
	return 0;
}

/*

*/