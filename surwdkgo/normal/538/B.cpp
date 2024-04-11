#include <stdio.h>
int main() {
	int n, dig[10];
	scanf("%d", &n);
	int nd = 0;
	while (n) {
		dig[nd++] = n%10;
		n/=10;
	}
	int max = 0;
	for (int i=0; i<nd; i++) {
		if (dig[i] > max) max = dig[i];
	}
	printf("%d\n", max);
	for (int i=0; i<max; i++) {
		int a = 0, t = 1;
		for (int j=0; j<nd; j++) {
			if (dig[j] > i) {
				a = a+t;
			}
			t = t*10;
		}
		printf("%d%c", a, i==max-1?'\n':' ');
	}
	return 0;
}