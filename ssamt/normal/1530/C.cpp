#include <stdio.h>
#include <stdlib.h>
#include <vector>

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
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		qsort(a, n, 4, cmp);
		qsort(b, n, 4, cmp);
		int sa = 0, sb = 0;
		for(i=n/4; i<n; i++) {
			sa += a[i];
			sb += b[i];
		}
		int answer = 0;
		while(sa < sb) {
			sa += 100;
			answer++;
			if((n+answer)/4 >= answer) {
				sb += b[(n+answer)/4-answer];
			}
			if((n+answer)%4 == 0) {
				sa -= a[(n+answer)/4-1];
				if((n+answer)/4 >= answer) {
					sb -= b[(n+answer)/4-answer];
				}
			}
		}
		printf("%d\n", answer);
	}
}