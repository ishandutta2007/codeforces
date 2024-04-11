#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int k[n], h[n];
		for(i=0; i<n; i++) {
			scanf("%d", &k[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &h[i]);
		}
		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				if(k[j]-k[i] < h[j]) {
					h[j] = max(h[j], h[i]+k[j]-k[i]);
					h[i] = 0;
				}
			}
		}
		long long answer = 0;
		for(i=0; i<n; i++) {
			answer += (long long)h[i]*(h[i]+1)/2;
		}
		printf("%lld\n", answer);
	}
}