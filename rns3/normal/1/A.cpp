#include <stdio.h>

int m, n, a;

int main() {
	scanf("%d %d %d", &n, &m, &a);
	printf("%I64d\n", ((n - 1ll) / a + 1) * ((m - 1ll) / a + 1));
	return 0;
}