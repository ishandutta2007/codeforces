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

int n, a[MAXN], b[MAXN];
bool f[2][MAXN];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
		if (a[i] > b[i]) {
			SWAP(a[i], b[i]);
		}
	}
	f[0][1] = f[1][1] = true;
	for (int i = 2; i <= n; i++) {
		if (a[i] <= a[i - 1]) {
			f[0][i] |= f[0][i - 1];
		}
		if (a[i] <= b[i - 1]) {
			f[0][i] |= f[1][i - 1];
		}
		if (b[i] <= b[i - 1]) {
			f[1][i] |= f[1][i - 1];
		}
		if (b[i] <= a[i - 1]) {
			f[1][i] |= f[0][i - 1];
		}
	}
	printf("%s\n", f[0][n] || f[1][n] ? "YES" : "NO");
	return 0;
}

// By Sooke.