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

const int maxn = 6000;

struct edge {
	int nxt, to;
}e[maxn];
int head[maxn], cnt, dis[maxn][maxn], pt[4], q[maxn];
int tmp, n, m, ans;
bool vis[maxn];

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

PII go[maxn][3], ar[maxn][3];

void Go(int u, int v) {
	if (dis[u][v] > go[u][0].se) {
		go[u][2] = go[u][1];
		go[u][1] = go[u][0];
		go[u][0] = mk(v, dis[u][v]);
	}
	else if (dis[u][v] > go[u][1].se) {
		go[u][2] = go[u][1];
		go[u][1] = mk(v, dis[u][v]);
	} 
	else if (dis[u][v] > go[u][2].se) {
		go[u][2] = mk(v, dis[u][v]);
	} 
}

void Ar(int u, int v) {
	if (dis[u][v] > ar[v][0].se) {
		ar[v][2] = ar[v][1];
		ar[v][1] = ar[v][0];
		ar[v][0] = mk(u, dis[u][v]);
	}
	else if (dis[u][v] > ar[v][1].se) {
		ar[v][2] = ar[v][1];
		ar[v][1] = mk(u, dis[u][v]);
	} 
	else if (dis[u][v] > ar[v][2].se) {
		ar[v][2] = mk(u, dis[u][v]);
	} 
//	printf("u = %d :", v);
//	For(i, 0, 2) printf(" x = %d y = %d", ar[v][i].fi, ar[v][i].se);puts("");
}

void bfs(int s) {
	memset(q, 0, sizeof q);
	memset(vis, 0, sizeof vis);
	int h = 0, t = 1;
	q[vis[s] = 1] = s;
	while (h < t) {
		int u = q[++h];
		Edge(i, u) {
			int v = e[i].to;
			if (vis[v]) continue;
			vis[v] = 1;
			dis[s][v] = dis[s][u] + 1;
			Go(s, v);
			Ar(s, v);
			q[++t] = v;
		}
	}
}

bool chk(int u, int v, int x, int y) {
	int _pt[4] = {ar[u][x].fi, u, v, go[v][y].fi};
	if (!ar[u][x].fi || !go[v][y].fi) return 0;
//	For(i, 0, 3) printf("%d ", _pt[i]);puts("");
	For(i, 0, 3) For(j, i + 1, 3) if (_pt[i] == _pt[j]) return 0;
//	puts("---------");
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, m) {
		int u = rdi(), v = rdi();
		insert(u, v);
	}
	For(i, 1, n) bfs(i);
//	For(i, 1, n) printf("%d %d %d\n", ar[i][0].fi, ar[i][1].fi, ar[i][2].fi); 
	For(i, 1, n) {
		For(j, 1, n) {
			if (i == j || dis[i][j] == 0) continue;
			For(x, 0, 2) {
				For(y, 0, 2) {
					if (!chk(i, j, x, y)) continue;
					if ((tmp = ar[i][x].se + dis[i][j] + go[j][y].se) > ans) {
			//			puts("!!!!!!!!!");
						pt[0] = ar[i][x].fi;
						pt[1] = i;
						pt[2] = j;
						pt[3] = go[j][y].fi;
						ans = tmp;
					}
				}
			}
		}
	}
	For(i, 0, 3) write(pt[i]), putchar(32);
	return 0;
}