#include <bits/stdc++.h>
using namespace std;

#define N 2000020

const int mod = 1e9 + 7;
int fac[N], rfac[N], ri[N];
void init() {
	fac[0] = 1;
	for (int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
	rfac[0] = rfac[1] = 1, ri[1] = 1;
   	for(int i = 2; i < N; i ++){
      		int t = mod / i;
      		ri[i] = (1ll * t * (mod - ri[mod % i])) % mod;
      		rfac[i] = (1ll * rfac[i-1] * ri[i]) % mod;
   	}
}

int main() {
	init();
	int  n;
	scanf("%d", &n);
	printf("%d\n", 1ll * fac[2*n+2] * rfac[n+1] % mod * rfac[n+1] % mod - 1);
}