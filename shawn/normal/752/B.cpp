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

char a[1010], b[1010];
int A[1010], vis[1010], n, tot;
pii ans[1010];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	rds(a + 1);
	rds(b + 1);
	n = strlen(a + 1);
	For(i, 1, n) A[(int)a[i]] = (int)a[i];
	For(i, 1, n) {
		if (a[i] == b[i]) {
			if (A[(int)a[i]] != a[i]) return write(-1), 0;
			vis[(int)a[i]] = 1;
		}
		else if (a[i] != b[i]) {
			if (!vis[(int)a[i]] && !vis[(int)b[i]]) {
				A[(int)a[i]] = (int)b[i];
				A[(int)b[i]] = (int)a[i];
				vis[(int)a[i]] = 1;
				vis[(int)b[i]] = 1;
				ans[++tot].fi = (int)a[i];
				ans[tot].se = (int)b[i];
			}
			if (A[(int)a[i]] != (int)b[i]) return write(-1), 0;
		}
		
	}
	write(tot), putchar(10);
	For(i, 1, tot) {
		putchar(ans[i].fi), putchar(32);
		putchar(ans[i].se), putchar(10);
	}
	return 0;
}

/*

*/