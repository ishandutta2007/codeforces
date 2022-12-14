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

int a[5][5];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	for (int i = 0; i < 4; i ++) for (int j = 0; j <= 3; j ++) a[i][j] = rdi();
	for (int i = 0; i < 4; i ++) { // 0l 1s 2r 3p
		if (a[i][3]) {
			for (int j = 0; j < 3; j ++) if (a[i][j]) return puts("YES"), 0;
			if (a[(i + 2) % 4][1]) return puts("YES"), 0;
			if (a[(i + 1) % 4][0]) return puts("YES"), 0;
			if (a[(i + 3) % 4][2]) return puts("YES"), 0;
		}	
	}
	return puts("NO"), 0;
}