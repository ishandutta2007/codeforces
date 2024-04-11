#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, m;
	char s[101];
	int decide;
	int possible;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		decide = -1;
		possible = 1;
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++) {
			scanf("%s", s);
			if(possible) {
				for(j=0; j<m; j++) {
					if(decide == -1) {
						if(s[j] == 'W') {
							decide = (i+j+1)%2;
						} else if(s[j] == 'R') {
							decide = (i+j)%2;
						}
					} else if(decide == 0) {
						if((s[j] == 'W' && (i+j)%2 == 0) || (s[j] == 'R' && (i+j)%2 == 1)) {
							possible = 0;
							break;
						}
					} else if(decide == 1) {
						if((s[j] == 'W' && (i+j)%2 == 1) || (s[j] == 'R' && (i+j)%2 == 0)) {
							possible = 0;
							break;
						}
					}
				}
			}
		}
		if(possible) {
			printf("YES\n");
			for(i=0; i<n; i++) {
				for(j=0; j<m; j++) {
					if(((i+j)%2 == 0) == (decide == 1)) {
						printf("W");
					} else {
						printf("R");
					}
				}
				printf("\n");
			}
		} else {
			printf("NO\n");
		}
	}
}