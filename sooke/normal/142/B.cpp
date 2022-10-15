#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
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

const int dc[4] = {0, 1, 2, 1};

int main() {
	for (int t = 1; t >= 1; t--) {
		lol n = read(), m = read();
		if (n > m) {
			SWAP(n, m);
		}
		if (n == 1) {
			printf("%lld\n", m);
		} else if (n == 2) {
			printf("%lld\n", m + dc[m % 4]);
		} else {
			printf("%lld\n", (n * m + 1) / 2);
		}
	}
	return 0;
}

// By Sooke.
// CF142B Help General.