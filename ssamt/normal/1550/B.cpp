#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n, a, b;
	char s[101];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &n, &a, &b);
		scanf("%s", s);
		if(b >= 0) {
			printf("%d\n", a*n+b*n);
		} else {
			int count = 1;
			for(i=1; i<n; i++) {
				if(s[i-1] != s[i]) {
					count++;
				}
			}
			printf("%d\n", a*n+b*((count+2)/2));
		}
	}
}