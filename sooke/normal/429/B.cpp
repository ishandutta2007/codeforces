#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807
#define INF MAXINT
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
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

#define MAXN 1005

int n, m, ans, a[MAXN][MAXN], lu[MAXN][MAXN], ld[MAXN][MAXN], ru[MAXN][MAXN], rd[MAXN][MAXN];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = read();
			lu[i][j] = MAX(lu[i - 1][j], lu[i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; j--) {
			ru[i][j] = MAX(ru[i - 1][j], ru[i][j + 1]) + a[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			ld[i][j] = MAX(ld[i + 1][j], ld[i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; j--) {
			rd[i][j] = MAX(rd[i + 1][j], rd[i][j + 1]) + a[i][j];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			ans = MAX(ans, lu[i][j - 1] + ru[i - 1][j] + ld[i + 1][j] + rd[i][j + 1]);
			ans = MAX(ans, lu[i - 1][j] + ru[i][j + 1] + ld[i][j - 1] + rd[i + 1][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF429B Working out.