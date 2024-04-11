#include <stdio.h>

long long n, k;

int main() {
	scanf("%I64d %I64d", &n, &k);
	if (k >= 1000000 || n < k * (k + 1) / 2) {
		puts("-1");
		return 0;
	}
	long long big = n / (k * (k + 1) / 2);
	if (big * big > n) {
		long long old = 1;
		for (long long i = 1; ; i ++) {
			if (i * i > n) i = n / old;
			if (n % i == 0) {
				if ((n / i) * (k * (k + 1)) / 2 <= n) {
					long long d = n / i;
					for (int j = 1; j < k; j ++) printf("%I64d ", j * d);
					printf("%I64d\n", n - d * k * (k - 1) / 2);
					return 0;
				}
				old = i;
			}
		}
	}
	for (int d = big; ; d --) if (n % d == 0) {
		for (int i = 1; i < k; i ++) printf("%d ", i * d);
		printf("%I64d\n", n - d * k * (k - 1) / 2);
		break;
	}
	return 0;
}