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

int n, max;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) { max = std::max(max, read() + read()); }
	std::cout << max;
	return 0;
}

// By Sooke.
// CF1047B Cover Points.