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
	scanf("%d", &n);
	int p[n];
	int start;
	for(i=0; i<n; i++) {
		p[i] = -1;
	}
	for(i=0; i<n; i++) {
		printf("? ");
		for(j=0; j<n; j++) {
			if(j == i) {
				printf("2 ");
			} else {
				printf("1 ");
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &k);
		k--;
		if(k >= 0) {
			if(k != i) {
				p[i] = k;
			}
		}
		printf("? ");
		for(j=0; j<n; j++) {
			if(j == i) {
				printf("1 ");
			} else {
				printf("2 ");
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &k);
		k--;
		if(k >= 0) {
			if(k != i) {
				p[k] = i;
			}
		} else {
			start = i;
		}
	}
	int a[n];
	for(i=0, j=start; j!=-1; j=p[j], i++) {
		a[j] = i;
	}
	printf("! ");
	for(i=0; i<n; i++) {
		printf("%d ", a[i]+1);
	}
	printf("\n");
}