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
#define For(i, j, k) for (int int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int int i = j; i >= k; i --)
#define Edge(i, u) for (int int i = head[u]; i; int i = e[i].nxt)

template<typename t> t read() {
	t x = 0;
	int f = 1;
	char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) {
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 20, M = 110;
int S[N], e[N], b[N], a[N][M], n, m, ans;
char s[M];

inline void solve() {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] == 0) {
			if (b[i + 1] == 0) {
				if (e[i]) sum += e[i] + e[i] - 1;
				else sum++;
			} else sum += m + 2;
		} else {
			if (b[i + 1] == 1) {
				if (S[i]) sum += (m + 2 - S[i]) + (m + 2 - S[i]) + 1;
				else sum++;
			} else sum += m + 2;
		}
	}
	if (b[n] == 0) sum += e[n] - 1;
	else sum += m + 2 - S[n];
	ans = min(ans, sum);
	return;
}
void dfs(int x) {
	if (x == n) {solve(); return;}
	for (int i = 0; i <= 1; i++) {
		b[x + 1] = i;
		dfs(x + 1);
	}
}
int main() {
	n = rdi(), m = rdi();
	for (int j, i = n; i; i--) {
		scanf("%s", s + 1);
		for (j = 1; j <= m + 2; j++) a[i][j] = s[j] - '0';
		for (j = 1; j <= m + 2; j++) if (a[i][j]) break;
		if (j > m + 2) S[i] = 0; else S[i] = j;
		for (j = m + 2; j; j--) if (a[i][j]) break;
		e[i] = j;
	}
	while (n && e[n] == 0) n--;
	ans = n * (m + 2); b[1] = 0; if (n) dfs(1);
	write(ans);
	return 0;
}