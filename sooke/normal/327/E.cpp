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

#define MAXN 25
#define P 1000000007

int n, m, a[MAXN], ban[MAXN], lg[1 << 24], f[1 << 24];
lol sum[1 << 24];

int main() {
	n = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
		lg[1 << i] = i;
	}
	m = read();
	for (int i = 1; i <= m; i++) {
		ban[i] = read();
	}
	f[0] = 1; //
	for (int i = 1; i < (1 << n); i++) {
		sum[i] = sum[i ^ LOWBIT(i)] + a[lg[LOWBIT(i)]];
		if (sum[i] != ban[1] && sum[i] != ban[2]) {
			for (int j = i; j > 0; j -= LOWBIT(j)) {
				f[i] += f[i ^ LOWBIT(j)];
				if (f[i] > P) {
					f[i] -= P;
				}
			}
		}
	}
	printf("%d\n", f[(1 << n) - 1]);
	return 0;
}

// By Sooke.
// CF327E Axis Walking.