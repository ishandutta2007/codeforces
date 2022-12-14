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

const int maxn = 1e5 + 10;
int b[maxn], c[maxn], n, m;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	int a[n + 10][m + 10];
	For(i, 1, n) For(j, 1, m) a[i][j] = rdi();
	For(i, 1, n) {
		For(j, 1, m) {
			int k = i;
			if (b[j] > i) k = b[j];
			else while (a[k + 1][j] >= a[k][j] && k < n) k ++;
			b[j] = k;
			c[i] = max(k, c[i]);
		}
	}
	for (int i = rdi(); i; i--) {
		int x = rdi(), y = rdi();
		puts(c[x] >= y ? "Yes" : "No");
	}
	return 0;
}