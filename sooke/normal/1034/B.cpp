#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const lol maxLongLong = 9223372036854775807ll;

lol n, m;

int main() {
	n = read(), m = read();
	if (n > m) { std::swap(n, m); }
	if (n == 1) {
		if (m % 6 >= 0 && m % 6 <= 3) { printf("%I64d\n", m / 6 * 6); }
		else if (m % 6 == 4) { printf("%I64d\n", m / 6 * 6 + 2ll); }
		else { printf("%I64d\n", m / 6 * 6 + 4ll); }
	} else if (n == 2) {
		if (m == 2) { printf("0\n"); }
		else if (m == 3) { printf("4\n"); }
		else if (m == 7) { printf("12\n"); }
		else { printf("%I64d\n", n * m); }
	} else if (n & 1) {
		if (m & 1) { printf("%I64d\n", n * m - 1ll); }
		else { printf("%I64d\n", n * m); }
	} else {
		printf("%I64d\n", n * m);
	}
	return 0;
}

// By Sooke.
// CF1034B Little C Loves 3 II.