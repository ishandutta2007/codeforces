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

int main() {
	int h, i, j, k, l;
	int t, n, m;
	int max_a = 1000;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int l[2*max_a+1];
		int up[2*max_a+1];
		for(i=0; i<=2*max_a; i++) {
			l[i] = INT_MAX;
		}
		l[0] = a[0];
		l[a[0]] = a[0];
		for(i=1; i<n; i++) {
			for(j=0; j<=2*max_a; j++) {
				up[j] = INT_MAX;
			}
			for(j=0; j<=2*max_a; j++) {
				if(l[j] != INT_MAX) {
					if(a[i] <= j) {
						up[j-a[i]] = min(up[j-a[i]], l[j]);
					} else {
						up[0] = min(up[0], l[j]-j+a[i]);
					}
					if(j+a[i] <= 2*max_a) {
						up[j+a[i]] = min(up[j+a[i]], max(l[j], j+a[i]));
					}
				}
			}
			copy(up, up+2*max_a+1, l);
			/*for(j=0; j<2*max_a; j++) {
				printf("%d ", l[j]);
			}
			printf("\n");*/
		}
		int answer = INT_MAX;
		for(i=0; i<=2*max_a; i++) {
			answer = min(answer, l[i]);
		}
		printf("%d\n", answer);
	}
}