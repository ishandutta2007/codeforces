#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, m;
	char s[200000+1];
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	int left, right;
	int count;
	int answer;
	int c[n][3][3]; //until - mod - letter
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			c[0][i][j] = 0;
		}
	}
	c[0][0][s[0]-'a']++;
	for(i=1; i<n; i++) {
		for(j=0; j<3; j++) {
			for(k=0; k<3; k++) {
				c[i][j][k] = c[i-1][j][k];
			}
		}
		c[i][i%3][s[i]-'a']++;
	}
	for(h=0; h<m; h++) {
		scanf("%d %d", &left, &right);
		int nc[3][3];
		for(i=0; i<3; i++) {
			count = (right+2-i)/3-((left+1-i)/3);
			for(j=0; j<3; j++) {
				if(left == 1) {
					nc[i][j] = c[right-1][i][j];
				} else {
					nc[i][j] = c[right-1][i][j]-c[left-2][i][j];
				}
				nc[i][j] = count-nc[i][j];
			}
		}
		answer = INT_MAX;
		for(i=0; i<3; i++) {
			for(j=0; j<3; j++) {
				for(k=0; k<3; k++) {
					if(i != j && j != k && k != i) {
						answer = min(answer, nc[0][i]+nc[1][j]+nc[2][k]);
					}
				}
			}
		}
		printf("%d\n", answer);
	}
}