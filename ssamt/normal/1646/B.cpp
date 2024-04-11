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
		long long a[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a, a+n);
		long long sum[n+1] = {};
		for(i=0; i<n; i++) {
			sum[i+1] = sum[i]+a[i];
		}
		if(sum[(n+1)/2] < sum[n]-sum[n/2+1]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}