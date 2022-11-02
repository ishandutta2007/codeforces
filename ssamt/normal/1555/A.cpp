#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t;
	long long n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		if(n < 6) {
			printf("15\n");
		} else {
			printf("%lld\n", (n+1)/2*5);
		}
	}
}