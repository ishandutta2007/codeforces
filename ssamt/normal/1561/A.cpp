#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int count = 0;
		while(1) {
			int check = 1;
			for(i=1; i<n; i++) {
				if(a[i-1] > a[i]) {
					check = 0;
					break;
				}
			}
			if(check) {
				break;
			}
			count++;
			if(count%2 == 0) {
				for(i=1; i<n; i+=2) {
					if(a[i] > a[i+1]) {
						int temp = a[i+1];
						a[i+1] = a[i];
						a[i] = temp;
					}
				}
			} else {
				for(i=0; i<n-1; i+=2) {
					if(a[i] > a[i+1]) {
						int temp = a[i+1];
						a[i+1] = a[i];
						a[i] = temp;
					}
				}
			}
		}
		printf("%d\n", count);
	}
}