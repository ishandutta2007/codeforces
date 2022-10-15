#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

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

#define MAXN 105

int n, m, cnt;
bool vis[MAXN];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		int l = read(), r = read();
		for (int j = l; j <= r; j++) {
			vis[j] = true;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}

// By Sooke.
// CF1015A Points in Segments.