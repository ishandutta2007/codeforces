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

LL power(LL a, LL b, LL p) {
	LL ret = 1;
	while (b) {
		if (b & 1) ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	for (LL te = rdi(); te; te --) {
		LL k = rdi(), l = rdi(), r = rdi(), p = rdi(), inv;
		if (p == 2) { puts(k & 1 ? "0" : "1"); continue; }
		if (k == 1) { write(2 % p); putchar(10); continue; }
		if (k & 1) inv = power(power(2, p - 2, p), r - l, p); else inv = 1;
		if (k % p == 0) { write(inv); putchar(10); continue; }
		LL a = power(k, power(2, r + 1, p - 1), p) - 1;
		LL b = power(k, power(2, l, p - 1), p) - 1;
		if (!b) write(power(2, r - l + 1, p) * inv % p), putchar(10);
		else write(a * inv % p * power(b, p - 2, p) % p), putchar(10);
	} 
	return 0;
}
/*
1
3 4 6 3

1
*/