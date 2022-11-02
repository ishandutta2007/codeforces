#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>

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
	int h, i, j, l;
	int t, n, m, k;
	long long mod = 1000000007;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		long long num = 0;
		for(i=31; i>=0; i--) {
			if(k&(1<<i)) {
				num = (num+pow_mod(n, i, mod))%mod;
			}
		}
		printf("%lld\n", num);
	}
}