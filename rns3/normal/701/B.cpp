#include <stdio.h>

#define N 100010

bool x[N], y[N];
int n, u, v, m, p, q;

int main() {
	scanf("%d %d", &n, &m);
	u = v = n;
	while (m) {
		scanf("%d %d", &p, &q);
		u -= 1 - x[p];
		x[p] = 1;
		v -= 1 - y[q];
		y[q] = 1;
		printf("%I64d", 1ll * u * v);
		m --;
		if (m) printf(" ");
	}
	return 0;
}