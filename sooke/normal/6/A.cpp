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

#define MAXN 5

int a[MAXN];

int main() {
	for (int i = 1; i <= 4; i++) {
		a[i] = read();
	}
	std::sort(a + 1, a + 4 + 1);
	for (int i = 1; i <= 4; i++) {
		for (int j = i + 1; j <= 4; j++) {
			for (int k = j + 1; k <= 4; k++) {
				if (a[i] + a[j] > a[k]) {
					printf("TRIANGLE\n");
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = i + 1; j <= 4; j++) {
			for (int k = j + 1; k <= 4; k++) {
				if (a[i] + a[j] == a[k]) {
					printf("SEGMENT\n");
					return 0;
				}
			}
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}

// By Sooke.
// CF6A Triangle.