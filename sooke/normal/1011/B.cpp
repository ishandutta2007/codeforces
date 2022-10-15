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

#define MAXN 105

int n, m, ans, a[MAXN], cnt[MAXN];

inline bool check(int d) {
	int tot = 0;
	for (int i = 1; i <= 100; i++) {
		tot += cnt[i] / d;
	}
	return tot >= n;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		a[i] = read();
		cnt[a[i]]++;
	}
	for (int l = 1, r = n + m, mid; l <= r; ) {
		mid = l + r >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1011B Planning The Expedition.