#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	long long k;
	long long n, x, t;
	long long answer;
	scanf("%lld", &k);
	for(h=0; h<k; h++) {
		scanf("%lld %lld %lld", &n, &x, &t);
		if(n >= t/x) {
			answer = (n-(t/x))*(t/x);
			answer += ((t/x)-1)*(t/x)/2;
		} else {
			answer = (n-1)*n/2;
		}
		printf("%lld\n", answer);
	}
}