#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int lim = 1000000;
int m[2000001];

int found(int* a, int n, int idx, int sum) {
	if(idx == n) {
		if(m[sum+lim] == 1) {
			return 1;
		} else {
			m[sum+lim] = 1;
			return 0;
		}
	} else {
		return (found(a, n, idx+1, sum+a[idx]) || found(a, n, idx+1, sum));
	}
}

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		memset(m, 0, sizeof(m));
		if(found(a, n, 0, 0)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}