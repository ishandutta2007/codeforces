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
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int all = 1;
		for(i=0; i<n; i++) {
			if(i+1 != a[i]) {
				all = 0;
				break;
			}
		}
		if(all) {
			printf("0\n");
		} else if(a[0] == 1 || a[n-1] == n) {
			printf("1\n");
		} else if(a[0] == n && a[n-1] == 1) {
			printf("3\n");
		} else {
			printf("2\n");
		}
	}
}