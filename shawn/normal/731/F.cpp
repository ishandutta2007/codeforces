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

const int maxn = 4e5 + 10;

int mx, a[maxn], n, sum[maxn];
ll ans, res;
bool f[maxn];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) {
		a[i] = rdi();
		mx = max(mx, a[i]);
	}
	For(i, 1, n) {
		sum[a[i]] ++;
	}
	For(i, 1, mx * 2) sum[i] += sum[i - 1];
	For(i, 1, n) {
		if (f[a[i]]) continue;
		f[a[i]] = 1;
		res = 0;
		for(int j = 1; j * a[i] <= mx; j ++) {
			res += 1ll * (j * a[i]) * (sum[(j + 1) * a[i] - 1] - sum[j * a[i] - 1]);
		}
		ans = max(ans, res);
	}
	write(ans);
	return 0;
}

/*

*/