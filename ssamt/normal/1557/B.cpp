#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int cmp(const void* num1, const void* num2) {
	int a = *(int*)num1;
	int b = *(int*)num2;
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
	long long t, n, k;
	long long s, m, e;
	int count;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld %lld", &n, &k);
		int a[n];
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		qsort(b, n, sizeof(int), cmp);
		count = 1;
		for(i=0; i<n-1; i++) {
			s = 0;
			e = n;
			while(s <= e) {
				m = (s+e)/2;
				if(b[m] > a[i]) {
					e = m;
				} else if(b[m] < a[i]) {
					s = m;
				} else if(b[m] == a[i]) {
					break;
				}
			}
			if(m == n-1 || b[m+1] != a[i+1]) {
				count++;
			}
		}
		if(count > k) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}