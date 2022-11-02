#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, k, l, r, r2;
	int t, n, m;
	int count;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		char s[m+1];
		int answer = INT_MAX;
		int a[n][m];
		for(i=0; i<n; i++) {
			scanf("%s", s);
			for(j=0; j<m; j++) {
				a[i][j] = s[j]-'0';
			}
		}
		int mem[m][n+1];
		for(i=0; i<m; i++) {
			mem[i][0] = 0;
			for(j=1; j<=n; j++) {
				mem[i][j] = mem[i][j-1]+a[j-1][i];
				//printf("%d", mem[i][j]);
			}
			//printf("\n");
		}
		for(i=0; i<n-4; i++) {
			for(j=i+4; j<n; j++) {
				for(k=0; k<m-3; k++) {
					count = 0;
					count += (j-i-1)-(mem[k][j]-mem[k][i+1]);
					for(r2=1; r2<=2; r2++) {
						if(a[i][k+r2] == 0) {
							count++;
						}
						if(a[j][k+r2] == 0) {
							count++;
						}
						count += mem[k+r2][j]-mem[k+r2][i+1];
					}
					for(l=k+3; l<m; l++) {
						if(count >= answer) {
							break;
						}
						count += (j-i-1)-(mem[l][j]-mem[l][i+1]);
						answer = min(answer, count);
						count -= (j-i-1)-(mem[l][j]-mem[l][i+1]);
						if(a[i][l] == 0) {
							count++;
						}
						if(a[j][l] == 0) {
							count++;
						}
						count += mem[l][j]-mem[l][i+1];
					}
				}
			}
		}
		printf("%d\n", answer);
	}
}