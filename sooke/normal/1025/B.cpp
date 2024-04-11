#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 150000;

lol gcd(lol a, lol b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n, x, y, m, pri[maxN];

int main() {
	n = read();
	x = read(), y = read();
	for (int i = 2; i * i <= x || i * i <= y; i++) {
		if (x % i == 0 || y % i == 0) {
			while (x % i == 0) {
				x /= i;
			}
			while (y % i == 0) {
				y /= i;
			}
			pri[++m] = i;
		}
	}
	if (x != 1) {
		pri[++m] = x;
	}
	if (y != 1 && x != y) {
		pri[++m] = y;
	}
	for (int i = 2; i <= n; i++) {
		x = read(), y = read();
		for (int j = 1; j <= m; j++) {
			if (pri[j] != 999 && x % pri[j] != 0 && y % pri[j] != 0) {
				pri[j] = 999;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (pri[i] != 999) {
			printf("%d\n", pri[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

// By Sooke.
// CF1025B Weakened Common Divisor.