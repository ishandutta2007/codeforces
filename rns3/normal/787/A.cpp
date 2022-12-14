#include <stdio.h>

int main() {
	int a, b, c, d, ans;
	scanf("%d %d\n%d %d", &a, &b, &c, &d);
	for (ans = b; ans <= 10000; ans += a) {
		if (ans >= d && (ans - d) % c == 0) break;
	}
	if (ans > 10000) ans = -1;
	printf("%d\n", ans);
	return 0;
}