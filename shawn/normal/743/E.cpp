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

const int inf = 2122219135;

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

const int maxn = 1010;

int col[10], a[maxn], g[maxn][maxn], L[maxn], f[maxn][300];
int ans, n, all, tot;

void pre() {
	For(i, 1, n) {
		if (!col[a[i]]) ++ tot;
		col[a[i]] = 1;
		For(j, i, n) {
			if (a[j] == a[i]) g[i][++ L[i]] = j;
		}
	}
}

bool jud(int len) {
	memset(f, -0x7f7f, sizeof f);
	f[0][0] = 0;
	For(i, 1, n) {
		For(j, 0, all) {
			f[i][j] = max(f[i][j], f[i - 1][j]);
			int k = a[i];
			if (j & k || f[i][j] < 0) continue;
			if (g[i][len]) f[g[i][len]][j | k] = max(f[g[i][len]][j | k], f[i][j] + len); 
			if (g[i][len - 1]) f[g[i][len - 1]][j | k] = max(f[g[i][len -  1]][j | k], f[i][j] + len - 1);
		}
	}
	if (f[n][all] == -inf) return 0;
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	all = (1 << 8) - 1;
	For(i, 1, n) a[i] = rdi();
	pre();
	if (tot != 8) return write(tot), 0;
	For(i, 1, n) a[i] = (1 << (a[i] - 1));
	int l = 0, r = n;
	jud(1);
	while (l <= r) {
		int mid = l + r >> 1;
		if (jud(mid)) ans = max(ans, f[n][all]), l = mid + 1;
		else r = mid - 1;
	}
	write(ans);
	return 0;
}

/*

*/