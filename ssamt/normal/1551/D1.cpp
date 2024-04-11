#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &n, &m, &k);
		if(n%2 == 0 && m%2 == 0) {
			if(k%2 == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else if(n%2 == 0 && m%2 == 1) {
			if(k%2 == 0 && k <= n*(m-1)/2) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else if(n%2 == 1 && m%2 == 0) {
			if((n*m/2-k)%2 == 0 && k >= m/2) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
}