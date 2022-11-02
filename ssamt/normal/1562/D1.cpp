#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, q;
	int l, r;
	char s[300001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &q);
		int count[n];
		scanf("%s", s);
		if(s[0] == '+') {
			count[0] = 1;
		} else {
			count[0] = -1;
		}
		for(i=1; i<n; i++) {
			if((s[i] == '+') == (i%2 == 0)) {
				count[i] = count[i-1]+1;
			} else {
				count[i] = count[i-1]-1;
			}
		}
		for(i=0; i<q; i++) {
			scanf("%d %d", &l, &r);
			int sum;
			if(l == 1) {
				sum = count[r-1];
			} else {
				sum = count[r-1]-count[l-2];
			}
			if((r-l+1)%2 == 0) {
				if(sum == 0) {
					printf("0\n");
				} else {
					printf("2\n");
				}
			} else {
				printf("1\n");
			}
		}
		
	}
}