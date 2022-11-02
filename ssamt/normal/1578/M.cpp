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
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long s[n+1] = {};
		for(i=1; i<=n; i++) {
			s[i] = s[i-1]+a[i-1];
		}
		int sq;
		for(sq=0; sq*(sq+1)/2<=n; sq++);
		sq--;
		long long m[sq+1][sq+1] = {};
		for(i=n-1; i>=0; i--) {
			for(j=1; j<=min(sq, n-i); j++) {
				if(j == 1 || s[i+j]-s[i] < m[(i+j)%(sq+1)][j-1]) {
					m[i%(sq+1)][j] = max(m[(i+1)%(sq+1)][j], s[i+j]-s[i]);
				} else {
					m[i%(sq+1)][j] = m[(i+1)%(sq+1)][j];
				}
			}
			/*for(j=1; j<=sq; j++) {
				printf("%d ", m[i%(sq+1)][j]);
			}
			printf("\n");*/
		}
		for(i=1; i<=sq && m[0][i]; i++);
		i--;
		printf("%d\n", i);
	}
}