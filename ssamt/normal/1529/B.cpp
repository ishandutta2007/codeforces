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
		sort(a, a+n);
		int interval = INT_MAX;
		for(i=0; i<n && a[i]<=0; i++) {
			if(i < n-1) {
				interval = min(interval, a[i+1]-a[i]);
			}
		}
		if(i != n && a[i] <= interval) {
			printf("%d\n", i+1);
		} else {
			printf("%d\n", i);
		}
	}
}