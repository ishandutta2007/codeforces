#include <stdio.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		if(n%3 == 0) {
			printf("%d %d\n", n/3, (n/3));
		} else if(n%3 == 1) {
			printf("%d %d\n", n/3+1, (n/3));
		} else {
			printf("%d %d\n", n/3, (n/3)+1);
		}
	}
}