#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	int t;
	int n, k;
	int test[20];
	int cur[20];
	int out;
	int num;
	int r;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		for(i=0; i<20; i++) {
			test[i] = 0;
			cur[i] = 0;
		}
		for(i=0; i<n; i++) {
			num = 0;
			for(j=19; j>=0; j--) {
				if(i%2 == 0) {
					out = (test[j]+cur[j])%k;
				} else {
					out = (k+cur[j]-test[j])%k;
				}
				num *= k;
				num += out;
				cur[j] = (k+out-cur[j])%k;
			}
			printf("%d\n", num);
			fflush(stdout);
			scanf("%d", &r);
			if(r == 1) {
				break;
			}
			test[0]++;
			for(j=0; j<20; j++) {
				if(test[j] == k) {
					test[j] = 0;
					test[j+1]++;
				} else {
					break;
				}
			}
		}
	}
}