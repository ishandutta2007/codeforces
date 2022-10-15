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
const int maxN = 105;

int n, m, max, used, a[maxN];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) { a[i] = read(), max = std::max(max, a[i]); }
	for (int i = max; i <= max + m; i++) {
		used = 0;
		for (int j = 1; j <= n; j++) { used += i - a[j]; }
		if (used >= m) { printf("%d %d\n", i, max + m); return 0; }
	}
	return 0;
}