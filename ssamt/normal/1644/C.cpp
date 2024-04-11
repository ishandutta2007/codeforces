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
		int x;
		scanf("%d %d", &n, &x);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int sum[n+1] = {};
		for(i=0; i<n; i++) {
			sum[i+1] = sum[i]+a[i];
		}
		int lar[n+1];
		for(i=0; i<=n; i++) {
			lar[i] = INT_MIN;
		}
		for(i=0; i<n; i++) {
			for(j=i; j<=n; j++) {
				lar[j-i] = max(lar[j-i], sum[j]-sum[i]);
			}
		}
		int l[n+2], r[n+2];
		l[0] = INT_MIN;
		for(i=0; i<=n; i++) {
			l[i+1] = max(l[i], lar[i]+x*i);
		}
		r[n+1] = INT_MIN;
		for(i=n; i>=0; i--) {
			r[i] = max(r[i+1], lar[i]);
		}
		for(i=0; i<=n; i++) {
			printf("%d ", max(l[i], r[i]+x*i));
		}
		printf("\n");
	}
}