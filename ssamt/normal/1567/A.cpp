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
		char r[n];
		scanf("%s", r);
		for(i=0; i<n; i++) {
			if(r[i] == 'U') {
				r[i] = 'D';
			} else if(r[i] == 'D') {
				r[i] = 'U';
			}
		}
		printf("%s\n", r);
	}
}