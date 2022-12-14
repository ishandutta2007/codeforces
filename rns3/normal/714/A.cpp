#include <stdio.h>

long long a, b, c, d, k;

int main() {
	scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &k);
	if (a < c) a = c;
	if (b > d) b = d;
	if (a > b) puts("0");
	else if (a <= k && k <= b) printf("%I64d\n", b - a);
	else printf("%I64d\n", b - a + 1);
	return 0;
}