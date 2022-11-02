#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i];
		}
		if(sum%n == 0) {
			int count = 0;
			for(i=0; i<n; i++) {
				if(a[i] > sum/n) {
					count++;
				}
			}
			printf("%d\n", count);
		} else {
			printf("-1\n");
		}
	}
}