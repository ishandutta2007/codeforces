#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

int n, x, a, b, c = INF, d = -INF;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if (x % 2 != 0 && x > 0) {
			a += x;
			c = min(c, x);
		}
		if (x % 2 != 0 && x < 0) {
			d = max(d, x);
		}
		if (x % 2 == 0 && x > 0) {
			b += x;
		}
	}
	if (a % 2 != 0) printf("%d\n", a + b);
	else {
		printf("%d\n", a + b - min(c, -d));
	}
	return 0;
}