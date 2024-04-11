#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::sort;

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
//
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

#define MAXN 200005

int n, m;
lol k, ans;

inline lol check(lol d) {
	lol cnt = 0, r = m;
	for (int i = 1; i <= n; i++) {
		while (r >= 1 && i * r > d) {
			r--;
		}
		cnt += r;
	}//////////////////////////////////////
	return cnt;
}

int main() {
	n = read(), m = read();
	scanf("%lld", &k);
	for (lol l = 1, r = 1LL * n * m, mid; l <= r; ) {
		mid = l + r >> 1;
		if (check(mid) >= k) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

// By Sooke.
// CF448D Multiplication Table.