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
#define rdl() read<ll>()
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

const int maxn = 1e7; 

int fa[maxn + 10], num[maxn + 10], ans[maxn + 10];
int tot, x, y, n, m, k;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
} 

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi(), k = rdi();
	For(i, 1, maxn) fa[i] = i;
	For(i, 1, n) {
		x = rdi() + 1;
		y = find(x);
		if (!y) return puts("-1"), 0;
		num[y]++;
		if (num[y] >= k) fa[y] = y - 1; 
	}
	For(i, 1, m) {
		x = rdi() + 1;
		y = find(x);
		if (!y) continue;
		ans[++tot] = i;
		num[y]++;
		if (num[y] >= k) fa[y] = y - 1; 
	}
	write(tot), putchar(10);
	For(i, 1, tot) write(ans[i]), putchar(32);
}