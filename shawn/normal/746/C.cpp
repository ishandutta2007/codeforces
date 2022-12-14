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

int ans, s, x1, x2, t1, t2, p, d, t;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	s = rdi(), x1 = rdi(), x2 = rdi();
	t1 = rdi(), t2 = rdi();
	p = rdi(), d = rdi();
	ans = abs(x2 - x1) * t2;
	if (x1 <= x2) {
		if (d == 1) {
			if (x1 >= p) t = (x2 - p) * t1;
			else t = (s + s - p + x2) * t1;
			ans = min(ans, t);
		}
		if (d == -1) {
			t = (p + x2) * t1;
			ans = min(ans, t);
		}
	}
	else {
		if (d == 1) {
			t = (s - p + s - x2) * t1;
			ans = min(ans, t);
		}
		if (d == -1) {
			if (x1 <= p) t = (p - x2) * t1;
			else t = (p + s + s - x2) * t1;
			ans = min(ans, t);
		}
	}
	write(ans);
	return 0;
}

/*

*/