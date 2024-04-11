#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int a[18] = {1, 2, 4, 5, 7, 8, 10, 11, 14, 16, 17, 19, 20, 22, 25, 26, 28, 29};
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		printf("%d\n", (n-1)/18*30+a[(n-1)%18]);
	}
}