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

template<typename t> void wt(t x) {
	if (x < 0) {
		putchar('-'), wt(-x);
		return;
	}
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int N = 2010;
char s[N * 2], ch;
int f[30][N], tot, m, n;

int main() {
	n = rdi(); scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) s[i + n] = s[i];
	for (int i = 1; i <= 26; i++) for (int j = 1; j <= n; j++) f[i][j] = 1000000000;
	for (int k = 1; k <= 26; k++) {
		for (int i = 1, j; i <= n; i++) {
			for(j = i, tot = 0; j <= n; j ++) {
				if (s[j] != 'a' + k - 1) tot++;
				f[k][j - i + 1] = min(f[k][j - i + 1], tot);
			}
		}
	}
	for (int Q = rdi(); Q; Q--) {
		m = rdi(), ch = getchar();
		while (ch < 'a' || ch > 'z') ch = getchar();
		int x = ch - 'a' + 1, l = 0 , r = n;
		int ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (f[x][mid] <= m) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		wt(ans), putchar(10);
	}
	return 0;
}