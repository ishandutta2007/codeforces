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

int n, m, a, b, q;

int main() {
	n = read(), m = read(), a = read(), b = read(), q = read();
	for (int i = 1; i <= q; i++) {
		int un = read(), uh = read(), vn = read(), vh = read();
		if (un == vn) {
			printf("%d\n", ABS(uh - vh));
		} else {
			if (uh < a) {
				if (vh < a) {
					printf("%d\n", ABS(un - vn) + a - uh + a - vh);
				} else if (vh > b) {
					printf("%d\n", ABS(un - vn) + vh - uh);
				} else {
					printf("%d\n", ABS(un - vn) + vh - uh);
				}
			} else if (uh > b) {
				if (vh < a) {
					printf("%d\n", ABS(un - vn) + uh - vh);
				} else if (vh > b) {
					printf("%d\n", ABS(un - vn) + uh - b + vh - b);
				} else {
					printf("%d\n", ABS(un - vn) + uh - vh);
				}
			} else {
				if (vh < a) {
					printf("%d\n", ABS(un - vn) + uh - vh);
				} else if (vh > b) {
					printf("%d\n", ABS(un - vn) + vh - uh);
				} else {
					printf("%d\n", ABS(un - vn) + ABS(uh - vh));
				}
			}
		}
	}
	return 0;
}

// By Sooke.
// CF1020A New Building for SIS.