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
	int h, i, j, k;
	int t, n, m;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int minval = INT_MAX;
		for(i=0; i<n; i++) {
			minval = min(minval, a[i]);
		}
		int count = 0;
		for(i=0; i<n; i++) {
			if(a[i] == minval) {
				count++;
			}
		}
		printf("%d\n", n-count);
	}
}