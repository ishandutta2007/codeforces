#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

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

const int maxN = 100005;

std::map<int, int> u, d;
int n, m, ans, a[maxN], b[maxN];

int main() {
	n = read(); read();
	for (int i = 1; i <= n; i++) { a[i] = read(); }
	m = read(); read();
	for (int i = 1; i <= m; i++) { b[i] = read(); }
	if (n * m == 1) { printf("2\n"); return 0; }
	for (int len = 2; len >= 0; len <<= 1) {
		u.clear(), d.clear();
		for (int i = 1; i <= n; i++) { u[a[i] % len]++; }
		for (int i = 1; i <= m; i++) { d[(b[i] + len / 2) % len]++; }
		for (int i = 1; i <= n; i++) { ans = std::max(ans, u[a[i] % len] + d[a[i] % len]); }
		for (int i = 1; i <= m; i++) { ans = std::max(ans, u[(b[i] + len / 2) % len] + d[(b[i] + len / 2) % len]); }
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1041F Ray in the tube.