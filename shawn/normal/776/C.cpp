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
typedef pair<LL, LL> PLL;

const LL inf = 0x7f7f7f7f;

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

const LL maxn = 100010;
const LL VAL = 1e14;

LL id[maxn], bit[maxn], a[maxn], n, ans, k, suf, one;
PLL b[maxn];

void add(LL x, LL v) {
	for (LL i = x; i <= n; i += i & -i) bit[i] += v;
}

LL query(LL x) {
	LL ret = 0;
	for (LL i = x; i; i -= i & -i) ret += bit[i];
	return ret;
}

LL lower(LL l, LL r, LL val) {	
	LL mid = l + r >> 1;
	while (l < r) {
		if (b[mid].fi >= val) r = mid;
		else l = mid + 1;
		mid = l + r - 1 >> 1;
	}
	return l;
}
LL upper(LL l, LL r, LL val) {	
	LL mid = l + r >> 1;
	while (l < r) {
		if (b[mid].fi <= val) l = mid;
		else r = mid - 1;
		mid = l + r + 1 >> 1;
	}
	return l;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), k = rdi();
	For(i, 1, n) a[i] = rdi(), b[b[i].se = i].fi = b[i - 1].fi + a[i];
	sort(b + 1, b + n + 1);
	For(i, 1, n) id[b[i].se] = i;
	suf = 0;
	For(i, 1, n) {
		one = 0;
		for (LL j = 1; abs(j) <= VAL; j *= k) {
			one++;
			if (k == -1 && one > 2) break;
			if (k == 1 && one > 1) break;
			LL P = j - suf;
			LL l = lower(1, n, P);
			if (b[l].fi != P) continue;
			LL r = upper(1, n, P);
			if (b[r].fi != P) continue;
			ans += (r - l + 1) - query(r) + query(l - 1);
		}
		suf -= a[i];
		add(id[i], 1);
	}
	write(ans);
	return 0;
}