#include <stdio.h>

int main() {
	int n, m, ans = 2;
	scanf("%d", &n);
	while (n --) {
		scanf("%d", &m);
		if (!(m % 2)) ans = 3 - ans;
		printf("%d\n", ans);
	}
	return 0;
}