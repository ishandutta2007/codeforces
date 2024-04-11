#include <stdio.h>

int main() {
	int n, m = 6;
	scanf("%d", &n);
	if (!n) m = 1;
	n %= 4;
	while (n --) m = m * 8 % 10;
	printf("%d\n", m);
	return 0;
}