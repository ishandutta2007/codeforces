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
		scanf("%d %d", &n, &m);
		char s[n*m+1];
		scanf("%s", s);
		int a[n*m];
		for(i=0; i<n*m; i++) {
			a[i] = s[i]-'0';
		}
		int col[n*m];
		int diff[n*m] = {};
		for(i=0; i<m; i++) {
			for(j=0; j<n && a[j*m+i]==0; j++);
			if(j < n) {
				diff[j*m+i] = 1;
			}
		}
		col[0] = diff[0];
		for(i=1; i<n*m; i++) {
			col[i] = col[i-1]+diff[i];
		}
		int row[n*m];
		int diff2[n][m] = {};
		int zero = m;
		for(i=0; i<n*m; i++) {
			if(a[i] && zero >= m) {
				diff2[i/m][i%m] = 1;
			}
			if(!a[i] && zero == m-1) {
				diff2[i/m][i%m] = -1;
			}
			if(a[i]) {
				zero = 0;
			}
			if(!a[i]) {
				zero++;
			}
		}
		for(i=0; i<m; i++) {
			row[i] = diff2[0][i];
			for(j=1; j<n; j++) {
				row[j*m+i] = row[(j-1)*m+i]+diff2[j][i];
			}
		}
		for(i=1; i<n*m; i++) {
			row[i] += row[i-1];
		}
		/*for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", diff2[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", row[i*m+j]);
			}
			printf("\n");
		}*/
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", col[i*m+j]+row[i*m+j]);
			}
		}
		printf("\n");
	}
}