#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long k;
		scanf("%d %lld", &n, &k);
		long long a[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a, a+n);
		long long sum[n+1] = {};
		for(i=0; i<n; i++) {
			sum[i+1] = sum[i]+a[i];
		}
		long long answer = LLONG_MAX;
		for(i=n; i>=1; i--) {
			if(k >= sum[i]-a[0]) {
				answer = min(answer, max(a[0]-(k-(sum[i]-a[0]))/(n+1-i), (long long)0)+n-i);
			} else {
				answer = min(answer, max(a[0]-(k-(sum[i]-a[0])-(n+1-i)+1)/(n+1-i), (long long)0)+n-i);
			}
		}
		printf("%lld\n", answer);
	}
}