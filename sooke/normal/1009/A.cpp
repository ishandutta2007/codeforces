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

#define MAXN 1005

int n, m, ans, a[MAXN], b[MAXN];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= m; i++) {
		b[i] = read();
	}
	for (int i = 1, j = 1; i <= m; i++) {
		int res = 0;
		for (; j <= n; j++) {
			if (b[i] >= a[j]) {
				res = j;
				break;
			}
		}
		if (res == 0) {
			break;
		} else {
			ans++;
			a[res] = MAXN;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1009A Game Shopping.