#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

int cmp(const void* num1, const void* num2) {
	char a = *(char*)num1;
	char b = *(char*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j, k;
	int t, n;
	char s[100];
	char sort[100];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		scanf("%s", s);
		for(i=0; i<n; i++) {
			sort[i] = s[i];
		}
		qsort(sort, n, 1, cmp);
		int answer = 0;
		for(i=0; i<n; i++) {
			if(s[i] != sort[i]) {
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}