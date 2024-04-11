#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j;
	int n, k;
	scanf("%d %d", &n, &k);
	int c[n*k];
	int found[n];
	int answer[n][2];
	for(i=0; i<n; i++) {
		for(j=0; j<2; j++) {
			answer[i][j] = -1;
		}
	}
	for(i=0; i<n*k; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	int count = 0;
	for(i=0; i<(n-1)/(k-1)+1; i++) {
		for(j=0; j<n; j++) {
			found[j] = -1;
		}
		for(j=0; count<(k-1)*(i+1) && count<n; j++) {
			if(answer[c[j]][0] == -1) {
				if(found[c[j]] != -1) {
					answer[c[j]][0] = found[c[j]];
					answer[c[j]][1] = j;
					count++;
					for(h=0; h<n; h++) {
						found[h] = -1;
					}
				} else {
					found[c[j]] = j;
				}
			}
		}
	}
	for(i=0; i<n; i++) {
		for(j=0; j<2; j++) {
			answer[i][j]++;
		}
	}
	for(i=0; i<n; i++) {
		printf("%d %d\n", answer[i][0], answer[i][1]);
	}
}