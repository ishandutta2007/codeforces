#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int i, j, k;
	int t, h, w;
	scanf("%d", &t);
	for(k=0; k<t; k++) {
		scanf("%d %d", &h, &w);
		for(i=0; i<w-1; i++) {
			if(i%2 == 0 && i != w-2) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("1\n");
		for(i=1; i<h-1; i++) {
			if(i%2 == 0 && i != h-2) {
				printf("1");
			} else {
				printf("0");
			}
			for(j=1; j<w-1; j++) {
				printf("0");
			}
			if(i%2 == 0 && i != h-2) {
				printf("1");
			} else {
				printf("0");
			}
			printf("\n");
		}
		for(i=0; i<w-1; i++) {
			if(i%2 == 0 && i != w-2) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("1\n");
		printf("\n");
	}
}