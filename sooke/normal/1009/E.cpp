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

#define P 998244353
#define MAXN 1000005

int n, a[MAXN];
lol ans, _pow, lst;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	_pow = 1;
	for (int i = n; i >= 1; i--) {
		ans = (ans + (lst * (n - i) + _pow) % P * a[i]) % P;
		lst = _pow;
		_pow = (_pow * 2) % P;
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF1009E Intercity Travelling.