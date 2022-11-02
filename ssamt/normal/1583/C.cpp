#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
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
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d %d", &n, &m);
	char a[n][m];
	char s[m+1];
	for(i=0; i<n; i++) {
		scanf("%s", s);
		for(j=0; j<m; j++) {
			a[i][j] = s[j];
		}
	}
	int count[m] = {};
	for(i=1; i<m; i++) {
		for(j=1; j<n; j++) {
			if(a[j][i-1] == 'X' && a[j-1][i] == 'X') {
				count[i]++;
			}
		}
	}
	int sum[m] = {};
	for(i=1; i<m; i++) {
		sum[i] = sum[i-1]+count[i];
	}
	int q;
	scanf("%d", &q);
	for(h=0; h<q; h++) {
		int x1, x2;
		scanf("%d %d", &x1, &x2);
		if(sum[x2-1]-sum[x1-1] == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}