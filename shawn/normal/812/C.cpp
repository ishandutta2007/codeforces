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
typedef unsigned long long UI;
typedef pair<long long, long long> PII;

const long long inf = 0x7f7f7f7f;

#define rdi() read<long long>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
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

const long long N = 1e5 + 10;

long long a[N], n, S;
long long b[N];

long long chk(long long mid) {
	long long sum = 0;
	for (long long i = 1; i <= n; i ++) b[i] = a[i] + i * mid;
	sort(b + 1, b + n + 1);
	for (long long i = 1; i <= mid; i ++) sum += b[i];
	if (sum <= S) return sum;
	else return -1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), S = rdi();
	for (long long i = 1; i <= n; i ++) a[i] = rdi();
	long long l = 0, r = n, ans1 = 0, ans2 = 0;
	while (l <= r) {
		long long mid = l + r >> 1;
		long long cost = chk(mid);
		if (cost != -1) ans1 = mid, ans2 = cost, l = mid + 1;
		else r = mid - 1;
	}
	printf("%I64d %I64d", ans1, ans2);
	return 0;
}