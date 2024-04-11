#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline lol read() {
	char c = getchar();
	lol n = 0;
	int f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 21

map<lol, int> M[MAXN];
int n, m, ms;
lol ans, k, a[MAXN][MAXN];

void dfs1(int x, int y, int step, lol res) {
	if (step == ms) {
		M[x][res]++;
		return;
	}
	if (x + 1 <= n) {
		dfs1(x + 1, y, step + 1, res ^ a[x + 1][y]);
	}
	if (y + 1 <= m) {
		dfs1(x, y + 1, step + 1, res ^ a[x][y + 1]);
	}
}
void dfs2(int x, int y, int step, lol res) {
	if (step == ms) {
		ans += M[x][res ^ k];
		return;
	}
	if (x - 1 > 0) {
		dfs2(x - 1, y, step - 1, res ^ a[x][y]);
	}
	if (y - 1 > 0) {
		dfs2(x, y - 1, step - 1, res ^ a[x][y]);
	}
}

int main() {
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = read();
		}
	}
	ms = (n + m - 2) / 2;
	dfs1(1, 1, 0, a[1][1]);
	dfs2(n, m, n + m - 2, 0);
	printf("%I64d\n", ans);
	return 0;
}