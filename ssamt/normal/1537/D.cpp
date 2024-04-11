#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	long long t;
	long long n;
	int count;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		count = 0;
		while(n%2 == 0) {
			n /= 2;
			count++;
		}
		if(count == 0) {
			printf("Bob\n");
		} else if(n == 1) {
			if(count%2 == 0) {
				printf("Alice\n");
			} else {
				printf("Bob\n");
			}
		} else {
			printf("Alice\n");
		}
	}
}