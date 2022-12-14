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

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a + 1)
#define mk(i, j) make_pair(i, j)
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)

template<typename t> t read() {
	t x = 0; int f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e3 + 10;

int n, b[maxn], tot;
bool f[maxn];
char a[maxn];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	
	n = rdi(), rds(a);
	For(i, 1, n) if (a[i] == 'g' && a[i - 1] == 'o' && a[i + 1] == 'o') b[++ tot] = i; 
	For(i, 1, tot) f[b[i]] = a[b[i] - 1] = a[b[i] + 1] = 1;
	For(i, 1, n) {
		if (!f[i] && 'a' <= a[i] && a[i] <= 'z') printf("%c", a[i]);
		if (f[i] && !f[i - 2]) printf("***");
	}
}

/* 
input
7
aogogob
output
a***b
*/