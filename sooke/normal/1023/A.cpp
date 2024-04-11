#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

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

int n, m;
std::string s, t;

inline int check() {
	for (int i = 1; i <= n; i++) {
		if (s[i] == '*') {
			return i;
		}
	}
	return -1;
}
inline bool test1(int u) {
	for (int i = 1; i <= u; i++) {
		if (s[i] != t[i]) {
			return false;
		}
	}
	return true;
}
inline bool test2(int u) {
	for (int i = 1; i <= u; i++) {
		if (s[n + 1 - i] != t[m + 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	n = read(), m = read();
	std::cin >> s >> t;
	s = " " + s;
	t = " " + t;
	int pos = check();
	if (pos != -1) {
		if (n > m + 1) {
			printf("NO\n");
			return 0;
		}
		if (test1(pos - 1) && test2(n - pos)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		if (s == t) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

// By Sooke.
// CF1023A Single Wildcard Pattern Matching.