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

int h, m, hh, mm, i, j, a[10];
char s[10];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%s", s);
	a[0] = s[0] - 48;
	a[1] = s[1] - 48;
	a[2] = s[3] - 48;
	a[3] = s[4] - 48;
	h = a[0] * 10 + a[1];
	m = a[2] * 10 + a[3];
	for (i = 0; i < 24 * 60; i ++) {
		if (h / 10 == m % 10 && h % 10 == m / 10) break;
		m ++;
		if (m == 60) m = 0, h ++, h %= 24;
	}
	printf("%d", i);
	return 0;
}