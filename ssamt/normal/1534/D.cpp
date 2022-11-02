#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n;
	int odd, even;
	int choose;
	scanf("%d", &n);
	int con[n][n];
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			con[i][j] = 0;
		}
	}
	printf("? 1\n");
	fflush(stdout);
	int a[n];
	int b[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	odd = 0;
	even = 0;
	for(i=0; i<n; i++) {
		if(a[i]%2 == 0) {
			even++;
		} else {
			odd++;
		}
		if(a[i] == 1) {
			con[0][i] = 1;
			con[i][0] = 1;
		}
	}
	if(even <= odd) {
		choose = 0;
	} else {
		choose = 1;
	}
	for(i=1; i<n; i++) {
		if(a[i]%2 == choose) {
			printf("? %d\n", i+1);
			fflush(stdout);
			for(j=0; j<n; j++) {
				scanf("%d", &b[j]);
				if(b[j] == 1) {
					con[i][j] = 1;
					con[j][i] = 1;
				}
			}
		}
	}
	printf("!\n");
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(con[i][j]) {
				printf("%d %d\n", i+1, j+1);
			}
		}
	}
}