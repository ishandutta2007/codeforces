#include <stdio.h>
#include <stdlib.h>
#include <vector>

int sort;

int cmp(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	int as = 0, bs = 0;
	int i;
	for(i=0; i<5; i++) {
		if(i == sort) {
			as += a[i];
			bs += b[i];
		} else {
			as -= a[i];
			bs -= b[i];
		}
	}
	if(as < bs) {
		return 1;
	} else if(as > bs) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int t, n;
	char s[400000];
	int max;
	int now, other;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int* c[n];
		for(i=0; i<n; i++) {
			scanf("%s", s);
			c[i] = (int*)malloc(5*sizeof(int));
			for(j=0; j<5; j++) {
				c[i][j] = 0;
			}
			for(j=0; s[j]; j++) {
				c[i][s[j]-'a']++;
			}
		}
		max = 0;
		for(sort=0; sort<5; sort++) {
			qsort(c, n, sizeof(int*), cmp);
			now = 0;
			other = 0;
			for(i=0; i<n; i++) {
				for(j=0; j<5; j++) {
					if(sort == j) {
						now += c[i][j];
					} else {
						other += c[i][j];
					}
				}
				if(now <= other) {
					break;
				}
			}
			if(i > max) {
				max = i;
			}
		}
		printf("%d\n", max);
	}
}