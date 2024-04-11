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

const int P = 1e9 + 7;
const int N = 1e6 + 10;
int n, now, l, r, ans;
char s[N];
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%s", s + 1);
	r = n = strlen(s + 1), l = 0;
	while (r && s[r] == 'a') r --;
	while (r) {
		l = r;
		for (;l > 1&& s[l - 1] == 'b'; l--);
		(now += r - l + 1) %= P;
		r = l - 1;
		for (;r && s[r] == 'a'; r--) (ans += now) %= P, (now *= 2) %= P;
	}
	write(ans);
	return 0;
}