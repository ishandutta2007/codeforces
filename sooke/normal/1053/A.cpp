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

inline lol power(lol a, lol b, lol p) { lol res = 1; for (; b; b >>= 1, a = a * a % p) { if (b & 1) { res = res * a % p; } } return res; }
lol gcd(lol a, lol b) { return b ? gcd(b, a % b) : a; }

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll;

int n, m, k, g, nown, nowm, nowk;

int main() {
	n = read(), m = read(), k = read();
	nown = n, nowm = m, nowk = k;
	g = gcd(n, k), n /= g, k /= g;
	g = gcd(m, k), m /= g, k /= g;
	if (k == 1) {
		if (n * 2 <= nown) { printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, 0, m, n * 2, 0); return 0; }
		n = nown, m = nowm, k = nowk;
		g = gcd(m, k), m /= g, k /= g;
		g = gcd(n, k), n /= g, k /= g;	
		if (m * 2 <= nowm) { printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, 0, m * 2, n, 0); return 0; }
	} else if (k == 2) { printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, 0, m, n, 0); return 0; }
	printf("NO\n");
	return 0;
}

// By Sooke.