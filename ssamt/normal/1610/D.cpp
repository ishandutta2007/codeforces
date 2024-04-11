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

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	int mod = 1000000007;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int twos[31] = {};
	for(i=0; i<n; i++) {
		int count = 0;
		while(a[i]%2 == 0) {
			a[i] /= 2;
			count++;
		}
		twos[count]++;
	}
	int back_sum[32];
	back_sum[31] = 0;
	for(i=30; i>=0; i--) {
		back_sum[i] = back_sum[i+1]+twos[i];
	}
	long long answer = (((long long)pow_mod(2, twos[0], mod)-1)*pow_mod(2, back_sum[1], mod))%mod;
	for(i=1; i<=30; i++) {
		if(twos[i] > 0) {
			answer = (answer+((long long)pow_mod(2, twos[i]-1, mod)-1)*pow_mod(2, back_sum[i+1], mod))%mod;
		}
	}
	printf("%lld\n", answer);
	
}