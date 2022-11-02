#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int q, n, k;
	int mint;
	scanf("%d", &q);
	for(h=0; h<q; h++) {
		fgetc(stdin);
		scanf("%d %d", &n, &k);
		int pos[n], temp[n];
		int l[n];
		int r[n];
		int t[n];
		for(i=0; i<k; i++) {
			scanf("%d", &pos[i]);
		}
		for(i=0; i<k; i++) {
			scanf("%d", &temp[i]);
		}
		for(i=0; i<n; i++) {
			t[i] = 0;
		}
		for(i=0; i<k; i++) {
			t[pos[i]-1] = temp[i];
		}
		mint = INT_MAX;
		for(i=n-1; i>=0; i--) {
			if(mint != INT_MAX) {
				mint++;
			}
			if(t[i]) {
				mint = min(mint, t[i]);
			}
			l[i] = mint;
		}
		mint = INT_MAX;
		for(i=0; i<n; i++) {
			if(mint != INT_MAX) {
				mint++;
			}
			if(t[i]) {
				mint = min(mint, t[i]);
			}
			r[i] = mint;
		}
		for(i=0; i<n; i++) {
			printf("%d ", min(l[i], r[i]));
		}
		printf("\n");
	}
}