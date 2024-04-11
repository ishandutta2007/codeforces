#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n;
	char s[20001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		scanf("%s", s);
		int l1, r1, l2, r2;
		int found = 0;
		for(i=0; i<(n+1)/2; i++) {
			if(s[i] == '0') {
				printf("%d %d %d %d\n", i+1, n, i+2, n);
				found = 1;
				break;
			}
		}
		if(!found) {
			for(i=(n+1)/2; i<n; i++) {
				if(s[i] == '0') {
					printf("%d %d %d %d\n", 1, i+1, 1, i);
					found = 1;
					break;
				}
			}
		}
		if(!found) {
			if(n%2 == 0) {
				printf("%d %d %d %d\n", 1, n, n/2+1, n);
			} else {
				printf("%d %d %d %d\n", 1, n-1, n/2+1, n-1);
			}
		}
	}
}