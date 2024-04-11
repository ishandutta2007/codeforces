#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	long long mod = 998244353;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long d[n+1][2] = {};
		d[0][0] = 1;
		for(i=0; i<n; i++) {
			int v = a[i];
			if(v != 0) {
				d[v-1][1] = (d[v-1][0]+2*d[v-1][1])%mod; 
			}
			d[v+1][1] = (2*d[v+1][1])%mod;
			d[v+1][0] = (d[v][0]+2*d[v+1][0])%mod;
		}
		long long answer = 0;
		for(i=0; i<=n; i++) {
			for(j=0; j<2; j++) {
				answer = (answer+d[i][j])%mod;
			}
		}
		answer = (answer-1+mod)%mod;
		printf("%lld\n", answer);
	}
}