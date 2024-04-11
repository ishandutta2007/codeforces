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
	int t, a, b;
	int NUM = 300000;
	int x[NUM+1];
	x[1] = 0;
	for(i=2; i<=NUM; i++) {
		x[i] = x[i-1]^(i-1);
	}
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &a, &b);
		int val = b^x[a];
		if(val == 0) {
			printf("%d\n", a);
		} else if(val == a) {
			printf("%d\n", a+2);
		} else {
			printf("%d\n", a+1);
		}
	}
}