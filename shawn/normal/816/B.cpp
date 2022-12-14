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

const int N = 2e5 + 10;
int a[N + 10], b[N + 10], n, k, q;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), k = rdi(), q = rdi();
	for (int i = 1; i <= n; i ++) {
		int l = rdi(), r = rdi();
		a[l] ++, a[r + 1] --;
	}
	for (int i = 1; i < N; i ++) a[i] += a[i - 1];
	for (int i = 1; i < N; i ++) if (a[i] >= k) b[i] ++;
	for (int i = 1; i < N; i ++) b[i] += b[i - 1];
//	for (int i = 91; i <= 97; i ++) printf("%d ", a[i]); puts("");
	for (int i = 1; i <= q; i ++) {
		int l = rdi(), r = rdi();
		write(b[r] - b[l - 1]), putchar(10);
	}
	return 0;
}