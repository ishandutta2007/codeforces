#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long h;
		scanf("%d %lld", &n, &h);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long start = 0, end = 1e18;
		while(start+1 < end) {
			long long mid = (start+end)/2;
			long long count = 0;
			for(i=0; i<n-1; i++) {
				count += min(mid, (long long)a[i+1]-a[i]);
			}
			count += mid;
			if(count < h) {
				start = mid;
			} else {
				end = mid;
			}
		}
		printf("%lld\n", end);
	}
}