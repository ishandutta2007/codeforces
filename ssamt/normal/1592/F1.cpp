#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main() {
	int h, i, j, k;
	int t, n, m, q;
	scanf("%d %d", &n, &m);
	char s[n][m];
	for(i=0; i<n; i++) {
		scanf("%s", s[i]);
	}
	int a[n][m];
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(s[i][j] == 'W') {
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}
	int acc[m] = {};
	int flip[n][m];
	for(i=n-1; i>=0; i--) {
		int sum = 0;
		for(j=m-1; j>=0; j--) {
			flip[i][j] = (acc[j]+sum+a[i][j])%2;
			sum += flip[i][j];
			acc[j] += sum;
		}
	}
	/*for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			printf("%d", flip[i][j]);
		}
		printf("\n");
	}*/
	int count = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			count += flip[i][j];
		}
	}
	int answer = count;
	for(i=1; i<n; i++) {
		for(j=1; j<m; j++) {
			if(flip[i-1][j-1] && flip[i-1][m-1] && flip[n-1][j-1] && flip[n-1][m-1]) {
				answer--;
				goto OUT;
			}
		}
	}
OUT:
	printf("%d\n", answer);
}