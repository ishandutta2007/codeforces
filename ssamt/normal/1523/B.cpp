#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		printf("%d\n", 3*n);
		for(i=0; i<n; i+=2) {
			for(j=0; j<3; j++) {
				printf("1 %d %d\n", i+1, i+2);
				printf("2 %d %d\n", i+1, i+2);
			}
		}
	}
}