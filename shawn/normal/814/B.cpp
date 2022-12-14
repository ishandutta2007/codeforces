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
typedef unsigned int UI;
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

int a[1100], b[1100], c[1100], d[1100], n;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	for (int i = 1; i <= n; i ++) a[i] = rdi();
	for (int i = 1; i <= n; i ++) b[i] = rdi();
	for (int i = 1; i <= n; i ++) if (a[i] == b[i]) c[i] = a[i], d[c[i]] = 1;
	for (int i = 1; i <= n; i ++) {
		if (c[i]) continue;
		if (!d[a[i]] && d[b[i]]) c[i] = a[i], d[c[i]] = 1;
		else if (!d[b[i]] && d[a[i]]) c[i] = b[i], d[c[i]] = 1;
	}
	for (int j, i = 1; i <= n; i ++) {
		if (c[i]) continue;
		for (j = 1; j <= n; j ++) if (!d[j]) break;
		c[i] = j;
		d[c[i]] = 1;
	}
	for (int i = 1; i <= n; i ++) printf("%d ", c[i]);
	return 0;
}
/*
4
3 2 1 3
4 2 1 2
*/