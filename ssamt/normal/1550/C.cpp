#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int start, end;
	int answer;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		answer = 2*n-1;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n-2; i++) {
			if(a[i] != a[i+1] && a[i+1] != a[i+2]) {
				if(!((a[i] < a[i+1] && a[i+1] < a[i+2]) || (a[i] > a[i+1] && a[i+1] > a[i+2]))) {
					answer++;
				}
			}
		}
		for(i=0; i<n-3; i++) {
			if(a[i] != a[i+1] && a[i+1] != a[i+2] && a[i+2] != a[i] && a[i+1] != a[i+3] && a[i+2] != a[i+3]) {
				if(((a[i+1] < a[i] && a[i] < a[i+2]) || (a[i+2] < a[i] && a[i] < a[i+1])) && ((a[i+1] < a[i+3] && a[i+3] < a[i+2]) || (a[i+2] < a[i+3] && a[i+3] < a[i+1]))) {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}