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

struct data {
	int id, l, r, x;
	
	bool operator < (const data &t) const {
		return x < t.x;
	}
}a[10010];
int n, m, p[10010], sum[10010];
bool ans[10010];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	for (int i = 1; i <= n; i ++) p[i] = rdi();
	for (int i = 1; i <= m; i ++) a[a[i].id = i].l = rdi(), a[i].r = rdi(), a[i].x = rdi();
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i ++) {
		if (a[i].x != a[i - 1].x) {
			for (int j = 1; j <= n; j ++) sum[j] = 0;
			for (int j = 1; j <= n; j ++) {
				sum[j] = sum[j - 1];
				if (p[j] < p[a[i].x]) sum[j]++;
			}
		}
		if (sum[a[i].r] - sum[a[i].l - 1] + 1 == a[i].x - a[i].l + 1) ans[a[i].id] = 1;
	}
	for (int i = 1; i <= m; i ++) puts(ans[i] ? "Yes" : "No");
	return 0;
}