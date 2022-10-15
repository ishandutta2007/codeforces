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

int n;

int main() {
	n = read();
	if (n % 3 == 0) { printf("%d %d %d\n", 1, 1, n - 2); }
	else if (n % 3 == 1) { printf("%d %d %d\n", 1, 2, n - 3); }
	else { printf("%d %d %d\n", 2, 2, n - 4); }
	return 0;
}

// By Sooke.
// CF1047A Little C Loves 3 I.