#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 998244353

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
	long long i, j, k;
	int t;
	int n, m;
	int one, zero;
	int count;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		char s[n+1];
		scanf("%s", s);
		one = 0;
		zero = 0;
		count = 0;
		for(j=0; j<n; j++) {
			if(s[j] == '0') {
				one += count/2;
				count = 0;
				zero++;
			} else if(s[j] == '1') {
				count++;
			}
		}
		one += count/2;
		printf("%d\n", comb_mod(zero+one, one, MOD));
	}
}