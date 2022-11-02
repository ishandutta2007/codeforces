#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

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
		int odd;
		int sum = 0;
		for(i=0; i<n; i++) {
			if(a[i]%2 == 1) {
				odd = i;
			}
			sum += a[i];
		}
		int comp = 0;
		for(i=2; i*i<=sum; i++) {
			if(sum%i == 0) {
				comp = 1;
			}
		}
		if(comp) {
			printf("%d\n", n);
			for(i=0; i<n; i++) {
				printf("%d ", i+1);
			}
			printf("\n");
		} else {
			printf("%d\n", n-1);
			for(i=0; i<n; i++) {
				if(i != odd) {
					printf("%d ", i+1);
				}
			}
			printf("\n");
		}
	}
}