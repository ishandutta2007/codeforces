#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
	long long i, j, k;
	int t;
	int n, m;
	int a_max = 100000;
	int o[a_max+1][2];
	int check;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		for(j=1; j<=a_max; j++) {
			for(k=0; k<2; k++) {
				o[j][k] = 0;
			}
		}
		for(j=0; j<n; j++) {
			scanf("%d", &a[j]);
			b[j] = a[j];
		}
		qsort(b, n, sizeof(int), cmp);
		for(j=0; j<n; j++) {
			o[a[j]][j%2]++;
			o[b[j]][j%2]--;
		}
		check = 1;
		for(j=1; j<=a_max; j++) {
			for(k=0; k<2; k++) {
				if(o[j][k] != 0) {
					check = 0;
					goto OUT;
				}
			}
		}
OUT:
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}