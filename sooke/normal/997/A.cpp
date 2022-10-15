#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 300001

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

inline char read() {
	char c = getchar();
	while (c != '0' && c != '1') {
		c = getchar();
	}
	return c ^ 48;
}

int N, t, lst = -1;
int n, x, y, u, v, a[Maxn];
long long ans;

int main() {
	scanf("%d%d%d", &N, &x, &y);
	for (int i = 1; i <= N; i++) {
		t = read();
		if (t != lst) {
			a[++n] = t;
		}
		lst = t;
	}
	if (a[1] == 0) {
		u = (n - 1) / 2;
		v = (n + 1) / 2;
	} else {
		if (n == 1) {
			printf("%d\n", 0);
			return 0;
		}
		u = (n - 2) / 2;
		v = n / 2;
	}
	ans = Min((long long)u * x + y, (long long)v * y);
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF997A Convert to Ones.