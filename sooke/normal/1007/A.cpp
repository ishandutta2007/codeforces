#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
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

#define MAXN 100005

int n, ans, a[MAXN], b[MAXN];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = b[i] = read();
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int la = 1, ra = n, lb = 1, rb = n; la <= ra; ) {
		if (a[ra] < b[lb]) {
			ra--, lb++, ans++;
		} else if (a[ra] < b[rb]) {
			ra--, rb--, ans++;
		} else {
			ra--, lb++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.