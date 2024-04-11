#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[2*n][2*n];
		for(i=0; i<2*n; i++) {
			for(j=0; j<2*n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		long long answer = 0;
		for(i=n; i<2*n; i++) {
			for(j=n; j<2*n; j++) {
				answer += a[i][j];
			}
		}
		int corner = INT_MAX;
		corner = min(corner, a[n][0]);
		corner = min(corner, a[n][n-1]);
		corner = min(corner, a[2*n-1][0]);
		corner = min(corner, a[2*n-1][n-1]);
		corner = min(corner, a[0][n]);
		corner = min(corner, a[0][2*n-1]);
		corner = min(corner, a[n-1][n]);
		corner = min(corner, a[n-1][2*n-1]);
		printf("%lld\n", answer+corner);
	}
}