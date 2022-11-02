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
	scanf("%d", &k);
	long long pow = pow_mod(2, k, mod-1);
	pow = (mod+pow-2)%mod;
	long long answer = pow_mod(4, pow, mod);
	answer = (6*answer)%mod;
	printf("%lld\n", answer);
}