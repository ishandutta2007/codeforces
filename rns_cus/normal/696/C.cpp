#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int m;
long long x, n;

int pow_mod(long long x, long long k){
	long long ret = 1;
	for(; k; k >>= 1){
		if(k & 1) ret = ret * x % mod;
		x = x * x % mod;
	} return ret;
}

int main(){
	n = 1;
	long long ti = (mod + 1) / 3;
	for(scanf("%d", &m); m --; ){
		scanf("%I64d", &x);
		x %= (mod - 1);
		n = n * x % (mod - 1);
	}
	n = (n + mod - 2) % (mod - 1);
	int p = pow_mod(2, n);
	int q = (n & 1) ? ti * (p + 1) % mod : ti * (p + mod - 1) % mod;
	printf("%d/%d\n", q, p);
}