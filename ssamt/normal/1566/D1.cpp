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

int cmp_first(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[0] > b[0]) {
		return 1;
	} else if(a[0] < b[0]) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int t, n, m;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		int a[m];
		for(i=0; i<m; i++) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		for(i=0; i<m; i++) {
			for(j=i+1; j<m; j++) {
				if(a[i] < a[j]) {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}