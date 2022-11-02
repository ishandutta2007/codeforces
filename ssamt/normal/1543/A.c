#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	long long i, j, k;
	int t;
	int n, m;
	long long a, b;
	long long temp;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%lld %lld", &a, &b);
		if(a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		if(a == b) {
			printf("0 0\n");
		} else {
			if(2*(a%(b-a)) > b-a) {
				printf("%lld %lld\n", b-a, b-a-a%(b-a));
			} else {
				printf("%lld %lld\n", b-a, a%(b-a));
			}
		}
	}
}