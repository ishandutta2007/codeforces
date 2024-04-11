#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int cmp(const void* num1, const void* num2) {
	long long* a = *(long long**)num1;
	long long* b = *(long long**)num2;
	if(a[1] > b[1]) {
		return 1;
	} else if(a[1] < b[1]) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	long long h, i, j;
	long long n;
	scanf("%lld", &n);
	long long* a[n];
	long long s, e;
	long long sum;
	long long answer;
	for(i=0; i<n; i++) {
		a[i] = (long long*)malloc(2*sizeof(long long));
		scanf("%lld %lld", &a[i][0], &a[i][1]);
	}
	qsort(a, n, sizeof(long long*), cmp);
	s = 0;
	e = n-1;
	sum = 0;
	answer = 0;
	while(s <= e) {
		if(a[s][1] <= sum) {
			sum += a[s][0];
			answer += a[s][0];
			a[s][0] = 0;
			s++;
		} else if(a[e][0] <= a[s][1]-sum) {
			sum += a[e][0];
			answer += 2*a[e][0];
			a[e][0] = 0;
			e--;
		} else {
			answer += 2*(a[s][1]-sum);
			a[e][0] -= a[s][1]-sum;
			sum += a[s][1]-sum;
		}
	}
	printf("%lld", answer);
}