#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	long long t;
	long long n, m;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld %lld %lld %lld", &n, &m, &i, &j);
		printf("%d %d %lld %lld\n", 1, 1, n, m);
	}
}