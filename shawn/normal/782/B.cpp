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

const int N = 60007;
int n;
PII a[N];

bool chk(DB mid) {
	DB r = a[1].fi + a[1].se * mid, l = a[1].fi;
	For(i, 2, n) {
		DB tmpr = a[i].fi + a[i].se * mid;
		DB tmpl = a[i].fi - a[i].se * mid;
		if (tmpl > r) return 0; 
		if (tmpl > l) l = tmpl;
		if (r > tmpr) r = tmpr;
	}
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) a[i].fi = rdi();
	For(i, 1, n) a[i].se = rdi();
	sort(a + 1, a + n + 1);
	DB l = 0, r = 1e9, mid, ans;
	For(i, 1, 200) {
		mid = (l + r) / 2.;
		if (chk(mid)) ans = mid, r = mid;
		else l = mid;
	}
	printf("%.7lf", ans);
	return 0;
}