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

const char out[2] = {'G', 'B'};

int n, k, a, b, c, f, num[2], ans[100010];

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = rdi(), k = rdi(), a = rdi(), b = rdi();
	num[0] = a, num[1] = b;
	if (a < b) f = 1;
	int i = 0, j;
	while (num[f] > num[f ^ 1] && num[f ^ 1] > 0) {
		j = min(num[f] - num[f ^ 1], k);
		num[f] -= j;
		num[f ^ 1] --;
		while(j --) ans[++ i] = f;
		ans[++ i] = f ^ 1;
	} 
	if (num[f ^ 1] == 0 && num[f] > k) return puts("NO"), 0;
	if (num[f ^ 1] == 0) for(;i <= n;) ans[++i] = f;
	else {
		for(;i <= n;f ^= 1) ans[++ i] = f;
	}
	For(i, 1, n) {
		printf("%c", out[ans[i]]);
	}
	return 0;
}

/*

*/