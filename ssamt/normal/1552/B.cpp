#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	char s[100];
	char sort[100];
	scanf("%d", &t);
	int r[50000][5];
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			for(j=0; j<5; j++) {
				scanf("%d", &r[i][j]);
			}
		}
		int idx = 0;
		for(i=1; i<n; i++) {
			int count = 0;
			for(j=0; j<5; j++) {
				if(r[i][j] < r[idx][j]) {
					count++;
				}
			}
			if(count >= 3) {
				idx = i;
			}
		}
		int found = 1;
		for(i=0; i<n; i++) {
			if(i != idx) {
				int count = 0;
				for(j=0; j<5; j++) {
					if(r[i][j] < r[idx][j]) {
						count++;
					}
				}
				if(count >= 3) {
					found = 0;
					break;
				}
			}
		}
		if(found) {
			printf("%d\n", idx+1);
		} else {
			printf("-1\n");
		}
	}
}