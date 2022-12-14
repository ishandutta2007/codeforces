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
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
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

int n, k, x, a[100010], mx[100010], mn[100010];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), k = rdi(), x = rdi();
	For(i, 1, n) a[i] = rdi();
	For(i, 1, k) {
		sort(a + 1, a + n + 1);
		mn[i] = a[1], mx[i] = a[n];
		if (i >= 2 && mn[i] == mn[i - 1] && mn[i - 1] == mn[i - 2] && mx[i] == mx[i - 1] && mx[i - 1] == mx[i - 2]) break;
		for (int j = 1; j <= n; j += 2) a[j] ^= x;
	}
	sort(a + 1, a + n + 1);
	write(a[n]), putchar(32), write(a[1]);
	return 0;
}