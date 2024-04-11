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
	int h, i, j, l;
	int t, n, m, k;
	int d;
	scanf("%d", &t);
	char in[20];
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &n, &m, &k);
		char a[n][m];
		bool b[n][m];
		for(i=0; i<n; i++) {
			scanf("%s", in);
			for(j=0; j<m; j++) {
				a[i][j] = in[j];
				b[i][j] = false;
			}
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				for(d=0; i-d>=0 && j-d>=0 && j+d<m; d++) {
					if(a[i-d][j-d] == '.' || a[i-d][j+d] == '.') {
						break;
					}
				}
				if(d > k) {
					for(l=0; l<d; l++) {
						b[i-l][j-l] = true;
						b[i-l][j+l] = true;
					}
				}
			}
		}
		int check = true;
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(a[i][j] == '*' && !b[i][j]) {
					check = false;
				}
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}