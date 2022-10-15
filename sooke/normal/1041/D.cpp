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
const int maxN = 500005;

int n, m, p = 1, l[maxN], r[maxN];
lol ans, tans, a[maxN], b[maxN];

int main() {
	n = read(), ans = m = read();
	for (int i = 1; i <= n; i++) { l[i] = read(), r[i] = read(); a[i] = a[i - 1] + r[i] - l[i]; }
	for (int i = 1; i < n; i++) { b[i] = b[i - 1] + l[i + 1] - r[i]; }
	b[n] = maxLongLong;
	for (int i = 1; i <= n; i++) {
		while (b[p] - b[i - 1] < m) { p++; }
		ans = std::max(ans, a[p] - a[i - 1] + m);
	}
	std::cout << ans << std::endl;
	return 0;
}