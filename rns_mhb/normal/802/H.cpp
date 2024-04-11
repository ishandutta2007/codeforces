#include <stdio.h>

int cnt[80];
#define f(k) k * (k - 1) * (k - 2) * (k - 3) / 24

int main() {
	int n;
	scanf("%d", &n);
	int k = 80;
	while (n) {
		while (f(k) > n) k --;
		n -= f(k);
		cnt[k] ++;
	}
	for (int i = 1; i < 80; i ++) {
		printf("a");
		while (cnt[i] --) printf("b");
	}
	puts(" aaaab");

	return 0;
}