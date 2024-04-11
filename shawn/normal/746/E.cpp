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

const int maxn = 2e5 + 10;

int n, m, a[maxn], num[2], odd, even, exct;
map <int, int> g;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, n) {
		a[i] = rdi();
		if (g[a[i]] == 0) g[a[i]] = 1;
		else a[i] = 0;
		if (a[i]) num[a[i] & 1] ++;
	}
	odd = 1, even = 2;
	For(i, 1, n) {
		if (!a[i]) {
			exct ++;
			if (num[0] > num[1]) {
				num[1] ++;
				for (; odd <= m && g[odd]; odd += 2);
				if (odd > m) return puts("-1"), 0;
				a[i] = odd;
				g[a[i]] = 1;
			}
			else {
				num[0] ++;
				for (; even <= m && g[even]; even += 2);
				if (even > m) return puts("-1"), 0;
				a[i] = even;
				g[a[i]] = 1;
			}
		}
	}
	for (int i = 1; i <= n && (num[0] > num[1]); i ++) {
		if (!(a[i] & 1)) {
			exct ++;
			for(; odd <= m && g[odd]; odd += 2);
			if (odd > m) return puts("-1"), 0;
			g[a[i]] = 0;
			a[i] = odd;
			g[a[i]] = 1;
			num[0] --, num[1] ++;
		}			
	}
	if (num[0] > num[1]) return puts("-1"), 0;
	for (int i = 1; i <= n && (num[0] < num[1]); i ++) {
		if (a[i] & 1) {
			exct ++;
			for(; even <= m && g[even]; even += 2);
			if (even > m) return puts("-1"), 0;
			g[a[i]] = 0;
			a[i] = even;
			g[a[i]] = 1;
			num[1] --, num[0] ++;
		}			
	}
	if (num[0] < num[1]) return puts("-1"), 0;
	write(exct), putchar(10);
	For(i, 1, n) write(a[i]), putchar(32);
	return 0;
	
}

/*

*/