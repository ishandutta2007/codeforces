#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> fac;

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

long long comb_mod(int n, int r, int mod) {
	long long answer = fac[n];
	answer = (answer*inv_mod(fac[r], mod))%mod;
	answer = (answer*inv_mod(fac[n-r], mod))%mod;
	return answer;
}

int main() {
	long long NUM = 200000;
	long long h, i, j;
	long long t, n;
	long long in;
	long long mod = 998244353;
	fac.push_back(1);
	for(i=1; i<=NUM; i++) {
		fac.push_back((fac[i-1]*i)%mod);
	}
	cin >> t;
	for(h=0; h<t; h++) {
		cin >> n;
		vector<int> a;
		vector<int> b;
		for(i=0; i<n; i++) {
			cin >> in;
			a.push_back(in);
			b.push_back(in);
		}
		sort(b.begin(), b.end());
		if(b[n-1]-b[n-2] == 0) {
			printf("%lld\n", fac[n]);
		} else if(b[n-1]-b[n-2] == 1) {
			for(i=n-2; i>=0 && b[i]+1==b[n-1]; i--);
			long long count = n-1-i-1;
			long long answer = 0;
			for(i=count; i<n; i++) {
				answer = (answer+((long long)comb_mod(n-count-1, n-i-1, mod)*fac[i])%mod*fac[n-i-1])%mod;
			}
			answer = (mod+fac[n]-answer)%mod;
			printf("%lld\n", answer);
		} else {
			printf("0\n");
		}
	}
}