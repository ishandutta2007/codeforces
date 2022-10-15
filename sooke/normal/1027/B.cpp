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

lol n, q;

int main() {
	n = read(), q = read();
	for (int i = 1; i <= q; i++) {
		lol x = read(), y = read();
		if ((x + y) % 2 == 0) {
			if (x % 2 == 1) {
				if (n % 2 == 0) {
					printf("%I64d\n", (x - 1) * n / 2 + y / 2 + 1);
				} else {
					printf("%I64d\n", (x - 1) * n / 2 + y / 2 + 1);
				}
			} else {
				if (n % 2 == 0) {
					printf("%I64d\n", (x - 1) * n / 2 + y / 2);
				} else {
					printf("%I64d\n", (x - 1) * n / 2 + y / 2 + 1);
				}
			}
		} else {
			if (x % 2 == 1) {
				if (n % 2 == 0) {
					printf("%I64d\n", (x - 1 + n) * n / 2 + y / 2);
				} else {
					printf("%I64d\n", (x - 1 + n) * n / 2 + y / 2 + 1);
				}
			} else {
				if (n % 2 == 0) {
					printf("%I64d\n", (x - 1 + n) * n / 2 + y / 2 + 1);
				} else {
					printf("%I64d\n", (x - 1 + n) * n / 2 + y / 2 + 1);
				}
			}
		}
	}
	return 0;
}

// By Sooke.
// CF1027B Numbers on the Chessboard.