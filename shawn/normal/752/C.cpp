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

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
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

const int maxn = 2e5 + 10;

char a[maxn];
int n, x, y, last, ans, xx, yy, xxx, yyy;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	rds(a + 1);
	xx = x = 2e5, yy = y = 2e5;
	last = 0;
	For(i, 1, n) {
		if (i == n) {
			ans++;
			break;
		}
		if (a[i] == 'R') xx ++;
		else if (a[i] == 'L') xx --;
		else if (a[i] == 'U') yy --;
		else if (a[i] == 'D') yy ++;
		
		xxx = xx, yyy = yy;
		if (a[i + 1] == 'R') xxx ++;
		else if (a[i + 1] == 'L') xxx --;
		else if (a[i + 1] == 'U') yyy --;
		else if (a[i + 1] == 'D') yyy ++;
		
		int step = i - last + 1;
		if (abs(xxx - x) + abs(yyy - y) != step) {
			ans ++;
			x = xx;
			y = yy;
			last = i;
		}
	}
	write(ans);
	return 0;
}

/*

*/