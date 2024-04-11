#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

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

int main() {
	int h, i, j, l;
	int t, n, m;
	scanf("%d", &t);
	int num = 100000;
	vector<long long> fac{1};
	long long mod = 1000000007;
	for(i=1; i<=2*num; i++) {
		fac.push_back((fac.back()*i)%mod);
	}
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		printf("%lld\n", (fac[2*n]*inv_mod(2, mod))%mod);
	}
}