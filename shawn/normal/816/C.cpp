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

#define pr pair<int,int>
#define N 110
int a[N][N], row[N], col[N], Min, j, len, k, ans, n, m, i, now;
vector < PII > Ans;

int main() {
	n = rdi(), m = rdi();
	Min = ans = inf;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) a[i][j] = rdi();
	for (i = 1; i <= m; i++) Min = min(Min, a[1][i]);
	for (k = 0; k <= Min; k++) {
		row[1] = k, now = k;
		for (j = 1; j <= m; j++) {
			col[j] = a[1][j] - k, now += col[j];
			if (col[j] < 0) break;
		}
		if (j <= m) continue;
		for (i = 2; i <= n; i++) {
			row[i] = a[i][1] - col[1];
			now += row[i];
			if (row[i] < 0) break;
			for (j = 1; j <= m; j++) if (a[i][j] - col[j] != a[i][1] - col[1]) break;
			if (j <= m) break;
		}
		if (i <= n) continue;
		if (now < ans) {
			ans = now, Ans.clear();
			for (i = 1; i <= n; i++) while (row[i]) Ans.push_back(make_pair(0, i)), row[i]--;
			for (i = 1; i <= m; i++) while (col[i]) Ans.push_back(make_pair(1, i)), col[i]--;
		}
	}
	if (ans == inf) return puts("-1"), 0;
	write(ans), putchar(10);
	len = Ans.size();
	for (i = 0; i < len; i++) {
		if (Ans[i].first == 0) printf("row %d\n", Ans[i].second);
		else printf("col %d\n", Ans[i].second);
	}
	return 0;
}