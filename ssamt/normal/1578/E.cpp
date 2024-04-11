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

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int a[n][m];
	int dx[4] = {0, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(h=0; h<k; h++) {
		int c;
		scanf("%d", &c);
		int x = 0;
		int y = c-1;
		while(x < n) {
			int key = a[x][y];
			a[x][y] = 2;
			x += dx[key];
			y += dy[key];
		}
		printf("%d ", y+1);
	}
	printf("\n");
}