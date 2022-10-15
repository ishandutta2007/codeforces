#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::string;

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

#define MAXN 1005

int n, m, q, pre[MAXN];
string s, t;
bool crr[MAXN];

inline bool check(int l, int r) {
	for (int i = l, j = 1; i <= r; i++, j++) {
		if (s[i] != t[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	n = read(), m = read(), q = read();
	std::cin >> s >> t;
	s = " " + s;
	t = " " + t;
	for (int i = m; i <= n; i++) {
		if (check(i - m + 1, i)) {
			crr[i] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + crr[i];
	}
	for (int i = 1; i <= q; i++) {
		int l = read() + m - 1, r = read();
		if (l > r) {
			printf("0\n");
		} else {
			printf("%d\n", pre[r] - pre[l - 1]);
		}
	}
	return 0;
}

// By Sooke.
// CF1016B Segment Occurrences.