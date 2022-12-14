#include <stdio.h>

int main() {
	int a, b, ans = 0;
	scanf("%d %d", &a, &b);
	while (a <= b) {
		ans ++;
		a *= 3;
		b *= 2;
	}
	printf("%d\n", ans);
	return 0;
}