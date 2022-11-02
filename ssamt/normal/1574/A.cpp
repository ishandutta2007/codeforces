#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j;
	int t, n;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			for(j=0; j<i; j++) {
				printf("()");
			}
			for(j=i; j<n; j++) {
				printf("(");
			}
			for(j=i; j<n; j++) {
				printf(")");
			}
			printf("\n");
		}
	}
	
}