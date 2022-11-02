#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int a, b, c;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &a, &b, &c);
		int n;
		if(a > b) {
			n = a-b;
		} else {
			n = b-a;
		}
		if(a > 2*n || b > 2*n || c > 2*n) {
			printf("-1\n");
		} else if(c > n) {
			printf("%d\n", c-n);
		} else {
			printf("%d\n", c+n);
		}
	}
}