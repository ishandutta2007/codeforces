#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int cmp(const void* num1, const void* num2) {
	int a = *(int*)num1;
	int b = *(int*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	int b[n];
	int ex[2];
	int num[n];
	for(i=1; i<n; i++) {
		printf("and %d %d\n", 1, i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	for(i=1; i<n; i++) {
		printf("or %d %d\n", 1, i+1);
		fflush(stdout);
		scanf("%d", &b[i]);
	}
	printf("and %d %d\n", 2, 3);
	fflush(stdout);
	scanf("%d", &ex[0]);
	printf("or %d %d\n", 2, 3);
	fflush(stdout);
	scanf("%d", &ex[1]);
	for(i=0; i<n; i++) {
		num[i] = 0;
	}
	for(i=0; i<32; i++) {
		int bit[n][2];
		for(j=1; j<n; j++) {
			bit[j][0] = a[j]&(1<<i);
			bit[j][1] = b[j]&(1<<i);
		}
		int check[2] = {1,1};
		for(j=1; j<n; j++) {
			if(bit[j][0]) {
				check[0] = 0;
			}
			if(!bit[j][1]) {
				check[1] = 0;
			}
		}
		if(check[0] && check[1]) {
			if(ex[0]&(1<<i)) {
				check[1] = 0;
			} else {
				check[0] = 0;
			}
		}
		if(check[0]) {
			for(j=1; j<n; j++) {
				if(bit[j][1]) {
					num[j] |= (1<<i);
				}
			}
		} else {
			num[0] |= (1<<i);
			for(j=1; j<n; j++) {
				if(bit[j][0]) {
					num[j] |= (1<<i);
				}
			}
		}
	}
	qsort(num, n, sizeof(int), cmp);
	printf("finish %d\n", num[k-1]);
}