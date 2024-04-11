#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d %d %d", &n, &l, &k);
	int d[n+1];
	for(i=0; i<n; i++) {
		scanf("%d", &d[i]);
	}
	d[n] = l;
	int a[n+1];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 0;
	int m[n+1][k+1];
	for(i=0; i<=k; i++) {
		m[0][i] = 0;
	}
	for(i=1; i<=n; i++) {
		for(j=0; j<=k; j++) {
			m[i][j] = INT_MAX;
			for(q=max(0, i-j-1); q<i; q++) {
				m[i][j] = min(m[i][j], m[q][j-(i-q-1)]+(d[i]-d[q])*a[q]);
			}
			//printf("%d %d:%d\n", i, j, m[i][j]);
		}
	}
	int answer = INT_MAX;
	for(i=0; i<=k; i++) {
		answer = min(answer, m[n][i]);
	}
	printf("%d\n", answer);
}