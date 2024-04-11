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

#define MAXN 100005

int n, m;
lol sum;

struct Song {
	int a, b;
} S[MAXN];

bool cmp(Song A, Song B) {
	return A.a - A.b > B.a - B.b;
}

inline lol solve() {
	if (sum <= 0) {
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		sum -= S[i].a - S[i].b;
		if (sum <= 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		S[i].a = read(), S[i].b = read();
		sum += S[i].a;
	}
	sum -= m;
	std::sort(S + 1, S + n + 1, cmp);
	printf("%I64d\n", solve());
	return 0;
}

// By Sooke.
// CF1015C Songs Compression.