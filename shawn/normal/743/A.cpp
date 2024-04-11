
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

int ans, n, a, b, st, ed;
char s[100010];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), a = rdi(), b = rdi();
	rds(s + 1);
	if (s[a] == s[b]) {
		puts("0");
		return 0;
	}
	if (a > b) swap(a, b);
	Rep(i, b, a) {
		if (s[i] == s[a]) {
			st = i;
			//ans = abs(i - b);
			break;
		}
	}
	For(i, st, b) {
		if (s[i] == s[b]) {
			ed = i;
			break;              
		}
	} 
	ans = ed - st;
	write(ans);
	return 0;
}

/*

*/