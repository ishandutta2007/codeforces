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

int a[5050], l[5050], r[5050], f[5050], n, ans;
bool vis[5050];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	for (int i = 0; i <= 5000; i ++) l[i] = n + 1;
	for (int i = 1; i <= n; i ++) {
		a[i] = rdi();
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
	} 
	for (int i = 1; i <= n; i ++) {
		int R = i, w = 0;
		bool fg = 1;
		memset(vis, 0, sizeof vis);
		for (int j = i; j <= R; j ++) if (!vis[a[j]]){
			if (j != l[a[j]]) {
				fg = 0;
				break;
			}
			vis[a[j]] = 1, w ^= a[j], R = max(R, r[a[j]]);
		}
		if (fg) f[R] = max(f[R], ans + w);
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}