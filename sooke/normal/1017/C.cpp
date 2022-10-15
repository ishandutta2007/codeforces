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

int n, min = INF, mini;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		if (i + (n - 1) / i + 1 < min) {
			mini = i;
			min = i + (n - 1) / i + 1;
		}
	}
	int l = 1, r;
	while (true) {
		r = l + mini - 1;
		if (r <= n) {
			for (int i = r; i >= l; i--) {
				printf("%d ", i);
			}
			l = r + 1;
		} else {
			for (int i = n; i >= l; i--) {
				printf("%d ", i);
			}
			break;	
		}
	}
	return 0;
}

// By Sooke.
// CF1017C The Phone Number.