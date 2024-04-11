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
	long long h, i, j;
	long long n, k, x;
	scanf("%lld %lld %lld", &n, &k, &x);
	long long a[n];
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	qsort(a, n, sizeof(long long), cmp);
	long long gap[n];
	int len = 0;
	for(i=1; i<n; i++) {
		if(a[i]-a[i-1] > x) {
			gap[len] = (a[i]-a[i-1]-1)/x;
			len++;
		}
	}
	qsort(gap, len, sizeof(long long), cmp);
	for(i=0; i<len; i++) {
		if(gap[i] > k) {
			break;
		}
		k -= gap[i];
	}
	printf("%lld", len-i+1);
}