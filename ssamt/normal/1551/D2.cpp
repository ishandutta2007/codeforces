#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, m, k;
	int count;
	char set[2];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &n, &m, &k);
		char answer[n][m];
		if(n%2 == 0 && m%2 == 0) {
			if(k%2 == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
				continue;
			}
		} else if(n%2 == 0 && m%2 == 1) {
			if(k%2 == 0 && k <= n*(m-1)/2) {
				printf("YES\n");
				for(i=0; i<n/2; i++) {
					if(i%2 == 0) {
						answer[2*i][m-1] = 'y';
						answer[2*i+1][m-1] = 'y';
					} else {
						answer[2*i][m-1] = 'z';
						answer[2*i+1][m-1] = 'z';
					}
				}
			} else {
				printf("NO\n");
				continue;
			}
		} else if(n%2 == 1 && m%2 == 0) {
			if((n*m/2-k)%2 == 0 && k >= m/2) {
				printf("YES\n");
				for(i=0; i<m/2; i++) {
					if(i%2 == 0) {
						answer[n-1][2*i] = 'y';
						answer[n-1][2*i+1] = 'y';
					} else {
						answer[n-1][2*i] = 'z';
						answer[n-1][2*i+1] = 'z';
					}
				}
			} else {
				printf("NO\n");
				continue;
			}
		}
		count = 0;
		if(n%2 == 1 && m%2 == 0) {
			k -= m/2;
		}
		for(i=0; i<n/2; i++) {
			for(j=0; j<m/2; j++) {
				set[0] = 'a';
				set[1] = 'b';
				if(i%2 == 1) {
					set[0] += 4;
					set[1] += 4;
				}
				if(j%2 == 1) {
					set[0] += 2;
					set[1] += 2;
				}
				if(count < k/2) {
					answer[2*i][2*j] = set[0];
					answer[2*i][2*j+1] = set[0];
					answer[2*i+1][2*j] = set[1];
					answer[2*i+1][2*j+1] = set[1];
				} else {
					answer[2*i][2*j] = set[0];
					answer[2*i][2*j+1] = set[1];
					answer[2*i+1][2*j] = set[0];
					answer[2*i+1][2*j+1] = set[1];
				}
				count++;
			}
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%c", answer[i][j]);
			}
			printf("\n");
		}
	}
}