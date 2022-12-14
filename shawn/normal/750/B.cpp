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

int n, t, x, pos;
char d[10];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) {
		t = rdi(), rds(d);
		if (x == 0) pos = 0;
		else if (x == 20000) pos = 1;
		else pos = 2;
		if (pos == 0) {
			if (d[0] != 'S') return puts("NO"), 0;
		}
		else if (pos == 1) {
			if (d[0] != 'N') return puts("NO"), 0;
		}
		if (d[0] == 'N') {
			if (t > x) return puts("NO"), 0;
			x -= t; 
		}
		else if (d[0] == 'S') {
			if (t + x > 20000) return puts("NO"), 0;
			x += t;
		}
	}
	if (x != 0) return puts("NO"), 0;
	puts("YES");
	return 0; 
}

/*

*/