#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void cur(int* a, int* min_idx, int end) {
	if(end > 0) {
		printf("%d ", a[min_idx[end-1]]);
		cur(a, min_idx, min_idx[end-1]);
		for(int i=min_idx[end-1]+1; i<end; i++) {
			printf("%d ", a[i]);
		}
	}
}

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int min_idx[n];
		min_idx[0] = 0;
		for(i=1; i<n; i++) {
			if(a[min_idx[i-1]] <= a[i]) {
				min_idx[i] = min_idx[i-1];
			} else {
				min_idx[i] = i;
			}
		}
		cur(a, min_idx, n);
		printf("\n");
	}
}