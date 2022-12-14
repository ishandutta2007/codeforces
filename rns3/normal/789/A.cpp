#include <stdio.h>

int n, rlt = 0, k, a;

int main() {
	scanf("%d %d", &n, &k);
	while (n --) {
		scanf("%d", &a);
		rlt += (a - 1) / k + 1;
	}
	printf("%d\n", (rlt + 1) / 2);
	return 0;
}