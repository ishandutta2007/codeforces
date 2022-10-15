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

#define MAXN 300005

int n, nowx, nowy, t;
lol cur, ans, a[MAXN], b[MAXN], spa[MAXN], spb[MAXN], pa[MAXN], pb[MAXN];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		cur -= a[i];
		pa[i] = pa[i - 1] + a[i];
		spa[i] = spa[i - 1] + i * a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = read();
		cur -= b[i];
		pb[i] = pb[i - 1] + b[i];
		spb[i] = spb[i - 1] + i * b[i];
	}
	nowx = 1, nowy = 0, t = 1;
	while (nowy <= n) {
		if (nowx == 1) {
			ans = MAX(ans, cur + (spa[n] - spa[nowy]) + (pa[n] - pa[nowy]) * nowy + (pb[n] - pb[nowy]) * (n * 2 + nowy + 1) - (spb[n] - spb[nowy]));
		} else {
			ans = MAX(ans, cur + (spb[n] - spb[nowy]) + (pb[n] - pb[nowy]) * nowy + (pa[n] - pa[nowy]) * (n * 2 + nowy + 1) - (spa[n] - spa[nowy]));
		}
		nowx = 3 - nowx;
		nowy++;
		if (nowx == 2) {
			cur += a[nowy] * t + b[nowy] * (t + 1);
		} else {
			cur += b[nowy] * t + a[nowy] * (t + 1);
		}
		t += 2;
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF1016C Vasya And The Mushrooms.