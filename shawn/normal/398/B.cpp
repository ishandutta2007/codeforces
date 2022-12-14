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

double f[2020][2020];
int n, n2, r, l, R, L, m, a[2020], b[2020];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	n2 = n * n;
	For(i, 1, m) {
		int x = rdi(), y = rdi();
		a[x] == 0 ? r ++ : r;
		b[y] == 0 ? l ++ : l;
		a[x]++, b[y] ++; 
	} 
	Rep(i, n, r) {
		Rep(j, n, l) {
		if (i == n && j == n) continue;
	//		f[i][j] = f[i + 1][j + 1] * i * j + f[i + 1][j] * i * (n - j) + f[i][j + 1] * (n - i) * j + n2;
	//		f[i][j] /= n2 - (n - i) * (n - j);
			f[i][j] = f[i + 1][j + 1] * (n - i) * (n - j) + f[i][j + 1] * i * (n - j) + f[i + 1][j] * (n - i) * j + n2;
			f[i][j] /= n2 - i * j;
		}
	}	
	printf("%.12lf", f[r][l]);
	return 0;
}