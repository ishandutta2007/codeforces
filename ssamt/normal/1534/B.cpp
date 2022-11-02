#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		long long answer = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		if(n == 1) {
			printf("%d\n", a[0]);
		} else {
			if(a[0] > a[1]) {
				answer += a[0]-a[1];
				a[0] = a[1];
			}
			if(a[n-1] > a[n-2]) {
				answer += a[n-1]-a[n-2];
				a[n-1] = a[n-2];
			}
			for(i=1; i<n-1; i++) {
				if(a[i] > a[i-1] && a[i] > a[i+1]) {
					answer += a[i]-max(a[i-1], a[i+1]);
					a[i] = max(a[i-1], a[i+1]);
				}
			}
			answer += a[0];
			for(i=1; i<n; i++) {
				answer += abs(a[i-1]-a[i]);
			}
			answer += a[n-1];
			printf("%lld\n", answer);
		}
	}
}