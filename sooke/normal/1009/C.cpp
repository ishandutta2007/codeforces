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

lol n, m, x, d, ave;
double a, b;

int main() {
	n = read(), m = read();
	if (n % 2 == 0) {
		a = 1LL * (n / 2) * (n / 2);
		b = 1LL * n * (n - 1) / 2;
	} else {
		a = 1LL * (1 + n / 2) * (n / 2);
		b = 1LL * n * (n - 1) / 2;
	}
	for (int i = 1; i <= m; i++) {
		x = read(), d = read();
		ave += 1LL * x * n;
		if (d <= 0) {
			ave += a * d;
		} else {
			ave += b * d;
		}
	}
	printf("%.7lf\n", (double)ave / n);
	return 0;
}

// By Sooke.
// CF1009C Annoying Present.