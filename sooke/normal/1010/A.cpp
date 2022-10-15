#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807
#define INF MAXINT
#define lol long long

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

int n;
double m, ans = -1, a[MAXN], b[MAXN];

inline bool check(double d) {
	double used = 0.0;
	for (int i = 1; i <= n; i++) {
		used += (m + d - used) / a[i];
		used += (m + d - used) / b[i];
	}
	return used <= d;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	b[n] = read();
	for (int i = 1; i < n; i++) {
		b[i] = read();
	}
	for (double l = 0.0, r = 1000000001.0, mid; l + 0.0000001 <= r; ) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 0.0000001;
		} else {
			l = mid + 0.0000001;
		}
	}
	if (ans < 0) {
		printf("-1\n");
		return 0;
	}
	printf("%.6lf\n", ans);
	return 0;
}

// By Sooke.
// CF1010A Fly.