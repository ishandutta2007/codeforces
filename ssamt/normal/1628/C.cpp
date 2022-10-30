#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n][n];
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int answer = 0;
		for(i=0; i<2*n-1; i+=4) {
			if(i < n) {
				for(j=0; j<=i; j+=2) {
					answer ^= a[j][i-j];
					answer ^= a[n-1-j][i-j];
				}
			} else {
				for(j=0; j<2*n-1-i; j+=2) {
					answer ^= a[i-(n-1)+j][n-1-j];
					answer ^= a[n-1-(i-(n-1)+j)][n-1-j];
				}
			}
		}
		printf("%d\n", answer);
	}
}