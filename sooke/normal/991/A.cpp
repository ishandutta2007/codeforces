#include <cstdio>

int a, b, c, n, m;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &n);
	m = a + b - c;
	if (c > a || c > b || a > n || b > n || c > n) {
		printf("-1\n");
		return 0;
	}
	if (m < n) {
		printf("%d\n", n - m);	
	} else {
		printf("-1\n");
	}
	return 0;
}

// By Sooke.
// CF991A If at first you don't succeed...