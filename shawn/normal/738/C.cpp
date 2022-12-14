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
	if (x < 0){ 
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 2e5 + 10;
const int maxv = 1e9 + 10;

struct Car{
	int c, v;
}car[maxn];

int n, k, s, t, g[maxn], mxg, mxv, ans;

bool jud(int x) {
	if (x < mxg) return 0;
	int tot = 0;
	For(i, 1, k + 1) {
	//	int l = g[i + 1] - g[i];
		tot += max(g[i] * 3 - x, g[i]);
		if (tot > t) return 0; 
	}
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), k = rdi(), s = rdi(), t = rdi();
	For(i, 1, n) car[i].c = rdi(), car[i].v = rdi();
	For(i, 1, k) g[i] = rdi();
	
	sort(g + 1, g + k + 1);
	g[k + 1] = s;
//	For(i, 1, k) mxg = max(mxg, g[i + 1] - g[i]);
	Rep(i, k + 1, 1) mxg = max(mxg, g[i] -= g[i - 1]);
	
	mxv = maxv;
	for (int l = 0, r = maxv, m; l <= r; jud(m = l + r >> 1) ? r = m - 1, mxv = m : l = m + 1);
	
	ans = maxv;
	For(i, 1, n) if (car[i].v >= mxv) ans = min(ans, car[i].c);
	ans = (ans == maxv || mxv == maxv) ? -1 : ans;
	
	write(ans);
	return 0;
}

/*
input
3 1 8 10
10 8
5 7
11 9
3
output
10
*/