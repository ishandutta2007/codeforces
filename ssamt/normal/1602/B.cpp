#include <stdio.h>
#include <limits.h>
#include <time.h>
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
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n+1][n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[0][i]);
		}
		int p[n+1];
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				p[j] = 0;
			}
			for(j=0; j<n; j++) {
				p[a[i-1][j]]++;
			}
			for(j=0; j<n; j++) {
				a[i][j] = p[a[i-1][j]];
			}
		}
		scanf("%d", &q);
		for(i=0; i<q; i++) {
			int x;
			scanf("%d %d", &x, &k);
			printf("%d\n", a[min(n, k)][x-1]);
		}
	}
}