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

vector <int> ans, tmp;

bool dig(int x) {
	int c[4];
	For(i, 0, 3) c[i] = x % 10, x /= 10;
	For(i, 0, 3) For(j, 0, 3) if (i != j && c[i] == c[j]) return 0;
	return 1;
}

pii chk(int x, int y) {
	int a[4], b[4]; bool app[10]; pii ret;
	memset(app, 0, sizeof app); ret.fi = ret.se = 0;
	For(i, 0, 3) a[i] = x % 10, app[a[i]] = 1, x /= 10;
	For(i, 0, 3) b[i] = y % 10, y /= 10;
	For(i, 0, 3) if (a[i] == b[i]) ret.fi ++; else if (app[b[i]]) ret.se ++;
	return ret;	
}

int cal(int x) {
	int num[5][5];
	memset(num, 0, sizeof num);
	int siz = ans.size() - 1;
	For(i, 0, siz) {
		pii t = chk(ans[i], x);
		num[t.fi][t.se] ++;
	}
	int ans = 0;
	For(i, 0, 4) For(j, 0, 4) ans = max(ans, num[i][j]);
	return ans;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	For(i, 0, 9999) if (dig(i)) ans.pb(i);
//	cal(123);
	while (ans.size() > 1) {
		int siz = ans.size() - 1;
		int mn = inf, out;
		For(i, 0, siz) {
			int t = cal(ans[i]);
			if (t < mn) mn = t, out = ans[i];
		}
		printf("%04d\n", out);
		fflush(stdout);
		pii x; x.fi = rdi(), x.se = rdi();
		tmp = ans;
		ans.clear();
//		chk(124, out);
		For(i, 0, siz) if (chk(tmp[i], out) == x) ans.pb(tmp[i]);
	}
	printf("%04d\n", ans[0]);
	fflush(stdout);
	return 0;
}

/*

*/