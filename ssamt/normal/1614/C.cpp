#include <bits/stdc++.h>

using namespace std;

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

//p must be prime
int inv_mod(int a, int p) {
	return pow_mod(a, p-2, p);
}

//mod must be prime
int comb_mod(int n, int r, int mod) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r, mod);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i, mod))%mod;
	}
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	long long mod = 1000000007;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		long long answer = 0;
		int l[m], r[m];
		int x[m];
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &l[i], &r[i], &x[i]);
		}
		for(i=0; i<30; i++) {
			int found = 0;
			for(j=0; j<m; j++) {
				if(x[j]&(1<<i)) {
					found = 1;
				}
			}
			if(found) {
				answer = (answer+pow_mod(2, n-1+i, mod))%mod;
			}
		}
		printf("%lld\n", answer);
	}
}