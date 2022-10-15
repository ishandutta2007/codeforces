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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n, k, t, g;

int main() {
	n = read(), k = read();
	g = k;
	for (int i = 1; i <= n; i++) {
		t = read() % k;
		g = gcd(g, t);
	}
	printf("%d\n", k / g);
	for (int i = 0; i < k; i++) {
		if (i % g == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}

// By Sooke.
// CF1010C Border.