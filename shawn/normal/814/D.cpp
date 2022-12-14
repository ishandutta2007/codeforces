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


#define pi acos(-1.0)
#define lb long double
#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0;
	int f = 1;
	char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) {
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 3010;
lb ans;
struct cycle {
	int x, y, r;
} a[N];

struct edge {
	int to, nxt;
} e[N];

int n, tot, fa[N], head[N], dep[N];

void add_edge(int x, int y) {
	e[++tot].nxt = head[x], e[head[x] = tot].to = y;
}
void dfs(int x) {
	lb s = (lb)pi * a[x].r * a[x].r;
	if (!fa[x]) ans += s;
	else {
		if (dep[x] & 1) ans += s; else ans -= s;
	}
	for (int i = head[x]; i; i = e[i].nxt) dep[e[i].to] = dep[x] + 1, dfs(e[i].to);
}

int main() {
	n = rdi();
	for (int i = 1; i <= n; i++) a[i].x = rdi(), a[i].y = rdi(), a[i].r = rdi();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)if (a[j].r >= a[i].r && i != j) {
				LL d = (a[i].r - a[j].r) * 1ll * (a[i].r - a[j].r);
				LL _d = (a[i].x - a[j].x) * 1ll * (a[i].x - a[j].x) + (a[i].y - a[j].y) * 1ll * (a[i].y - a[j].y);
				if (d >= _d) {
					if (!fa[i]) fa[i] = j;
					if (a[fa[i]].r > a[j].r) fa[i] = j;
				}
			}
	for (int i = 1; i <= n; i ++) if (fa[i]) add_edge(fa[i], i);
	for (int i = 1; i <= n; i ++) if (!fa[i]) dfs(i);
	printf("%.12lf\n", (DB) ans);
	return 0;
}