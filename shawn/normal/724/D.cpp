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

const int maxn = 1e5 + 10;

int m, n, now, mn, top;
char s[maxn], a[maxn], mx;
bool inq[maxn];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	m = rdi();
	rds(a + 1);
	n = strlen(a + 1);
	now = 1;
/*	For(i, 1, n) {
		if (a[i] <= a[now]) now = i;
	}
	inq[now] = 1;
	s[top++] = a[now];
	mx = max(mx, a[now]);*/
	while(now + m - 1 <= n) {
		int mn = now;
		For(i, now + 1, now + m - 1) {
			if (a[i] <= a[mn]) mn = i;
		}
		inq[mn] = 1;
		s[top++] = a[mn];
		mx = max(mx, a[mn]);
		now = mn + 1;
	}
	For(i, 1, n) {
		if (a[i] < mx && !inq[i]) s[top++] = a[i]; 
	}
	sort(s, s + top);
	printf("%s", s);
	return 0;
}

/*

*/