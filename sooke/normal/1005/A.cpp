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

#define MAXN 1001

int n, t, a[MAXN], m, b[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	t = a[1];
	for (int i = 2; i <= n; i++) {
		if (t < a[i]) {
			t = a[i];
		} else {
			b[++m] = t;
			t = a[i];
		}
	}
	if (t != 0) {
		b[++m] = t;
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}

// By Sooke.
//