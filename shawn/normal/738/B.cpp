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

typedef long long ll;
typedef pair<int, int> pii;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a + 1)
#define mk(i, j) make_pair(i, j)
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)

template<typename t> t read() {
	t x = 0; int f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e4 + 10;

bool a[maxn][maxn];
int st, ed, n, m, ans;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, n) For(j, 1, m) a[i][j] = rdi();
	For(i, 1, n) {
		st = ed = 0;
		For(j, 1, m) {
			if (a[i][j]) {
				if (!st) st = ed = j;
				else ed = j;
			}
		}
		For(j, 1, m) {
			if (!a[i][j] && st) {
				if (st <= j && j <= ed) ans += 2;
				else ans ++;
			}
		}
	}
	For(j, 1, m) {
		st = ed = 0;
		For(i, 1, n) {
			if (a[i][j]) {
				if (!st) st = ed = i;
				else ed = i;
			}
		}
		For(i, 1, n) {
			if (!a[i][j] && st) {
				if (st <= i && i <= ed) ans += 2;
				else ans ++;
			}
		}
	}
	write(ans);
	return 0;
}

/*
input
4 4
0 0 0 0
1 0 0 1
0 1 1 0
0 1 0 0
output
20	
*/