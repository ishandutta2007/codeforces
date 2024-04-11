#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
	long long h, i, j;
	long long t, n, k;
	long long mod = 1000000007;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld %lld", &n, &k);
		long long answer;
		long long win, same;
		same = 0;
		win = 0;
		long long fac[n+1];
		fac[0] = 1;
		for(i=1; i<=n; i++) {
			fac[i] = (fac[i-1]*i)%mod;
		}
		for(i=0; i<n; i+=2) {
			same = (same+(fac[n]*inv_mod(fac[i], mod))%mod*inv_mod(fac[n-i], mod))%mod;
		}
		if(n%2 == 1) {
			same = (same+1)%mod;
		} else {
			win = 1;
		}
		answer = 0;
		if(win) {
			for(i=0; i<k; i++) {
				answer = ((long long)pow_mod(same, i, mod)*pow_mod(pow_mod(2, n, mod), k-i-1, mod)+answer)%mod;
			}
		}
		answer = (answer+pow_mod(same, k, mod))%mod;
		printf("%lld\n", answer);
	}
}