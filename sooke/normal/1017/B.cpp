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

inline int number() {
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	return c ^ 48;
}
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

#define MAXN 100005

int n, a[MAXN], b[MAXN];
lol x, y, u, v;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = number();
	}
	for (int i = 1; i <= n; i++) {
		b[i] = number();
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			if (b[i] == 0) {
				x++; // 0 0
			} else {
				y++; // 0 1
			}
		} else {
			if (b[i] == 0) {
				u++; // 1 0
			} else {
				v++; // 1 1
			}
		}
	}
	printf("%I64d\n", x * u + x * v + y * u);
	return 0;
}

// By Sooke.
// CF1017B The Bits.