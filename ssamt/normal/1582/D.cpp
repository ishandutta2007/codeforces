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
		if(n%2 == 0) {
			i = 0;
		} else {
			if(a[0] == a[1]) {
				if(a[2] > 1 || a[2] == -1) {
					printf("%d %d %d ", 1, a[2]-1, -a[0]);
				} else {
					printf("%d %d %d ", -1, a[2]+1, -a[0]);
				}
			} else if(a[1] == a[2]) {
				if(a[0] > 1 || a[0] == -1) {
					printf("%d %d %d ", -a[1], 1, a[0]-1);
				} else {
					printf("%d %d %d ", -a[1], -1, a[0]+1);
				}
			} else if(a[0] == a[2]) {
				if(a[1] > 1 || a[1] == -1) {
					printf("%d %d %d ", 1, -a[0], a[1]-1);
				} else {
					printf("%d %d %d ", -1, -a[0], a[1]+1);
				}
			} else {
				printf("%d %d %d ", a[1]-a[2], a[2]-a[0], a[0]-a[1]);
			}
			i = 3;
		}
		for(; i<n; i+=2) {
			printf("%d %d ", a[i+1], -a[i]);
		}
		printf("\n");
	}
}