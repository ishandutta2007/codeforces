#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int cmp(const void* num1, const void* num2) {
	long long a = *(long long*)num1;
	long long b = *(long long*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}


int main() {
	long long h, i, j, k;
	long long t, n;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		long long d[n];
		long long answer = 0;
		for(i=0; i<n; i++) {
			scanf("%lld", &d[i]);
		}
		qsort(d, n, sizeof(long long), cmp);
		for(i=0; i<n; i++) {
			if(i != 0) {
				answer -= (d[i]-d[i-1])*i*(n-i);
			}
		}
		answer += d[n-1];
		printf("%lld\n", answer);
	}
}