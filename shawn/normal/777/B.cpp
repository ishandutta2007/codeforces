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

int n, b[1010], a[1010], win, lose;
char s[1010];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(); 
	rds(s + 1);For(i, 1, n) a[i] = s[i] - 48;
	rds(s + 1);For(i, 1, n) b[i] = s[i] - 48;
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	int j = 1;
	For(i, 1, n) {
		while (j <= n && b[j] < a[i]) j++;
		if (j > n) lose++; else j++;
	}
	j = 1;
	For(i, 1, n) {
		while (j <= n && b[j] <= a[i]) j ++;
		if (j <= n) j ++, win ++;
	}
	printf("%d\n%d", lose, win);
	return 0;
}