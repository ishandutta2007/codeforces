#include <bits/stdc++.h>

using namespace std;

long long count(long long k, long long h) {
	if(h <= k) {
		return h*(h+1)/2;
	} else {
		long long m = 2*k-1-h;
		return k*k-m*(m+1)/2;
	}
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long k, x;
		scanf("%lld %lld", &k, &x);
		if(x <= k*k) {
			long long start = 0;
			long long end = 2*k;
			while(start+1 < end) {
				long long mid = (start+end)/2;
				if(count(k, mid) <= x) {
					start = mid;
				} else {
					end = mid;
				}
			}
			if(count(k, start) == x) {
				printf("%lld\n", start);
			} else {
				printf("%lld\n", end);
			}
		} else {
			printf("%lld\n", 2*k-1);
		}
	}
}