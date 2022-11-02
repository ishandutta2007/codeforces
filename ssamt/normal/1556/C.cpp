#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, m;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	long long sum[n+1];
	sum[0] = 0;
	for(i=1; i<=n; i++) {
		if(i%2 == 0) {
			sum[i] = sum[i-1]-a[i-1];
		} else {
			sum[i] = sum[i-1]+a[i-1];
		}
	}
	long long answer = 0;
	for(i=0; i<n; i+=2) {
		for(j=i+1; j<n; j+=2) {
			long long low = 0;
			for(k=i+1; k<j; k++) {
				low = min(low, sum[k+1]-sum[i+1]);
			}
			long long change = sum[j]-sum[i+1];
			if(change >= 0) {
				if(0 <= min(a[i], a[j]-change)+low) {
					answer += min(a[i], a[j]-change)+low+1;
				}
			} else {
				if(0 <= min(a[i]+change, a[j])+(low-change)) {
					answer += min(a[i]+change, a[j])+(low-change)+1;
				}
			}
			if(j == i+1) {
				answer--;
			}
		}
	}
	printf("%lld\n", answer);
}