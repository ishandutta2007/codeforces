#include <bits/stdc++.h>
using namespace std;
int T , n , m , k;
long long inv[2200000] , inc[1100000] , fac[1100000] , i2[1100000] , ans;
const int mod = 1e9 + 7 , inv2 = (mod + 1) / 2;
long long C( int a , int b )
{
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	inv[0] = inv[1] = fac[0] = fac[1] = inc[0] = inc[1] = 1;
	for(int i = 2 ; i <= 1000000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
	i2[0] = 1;
	for(int i = 1 ; i <= 1000000 ; i++ ) i2[i] = i2[i - 1] * inv2 % mod;
	
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &n , &m , &k); ans = 0;
		if(n == m) 
		{
			printf("%lld\n" , 1ll * n * k % mod);
			continue;
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			(ans += i * i2[n - i] % mod * C(n - i - 1 , m - i) % mod) %= mod;
		}
		printf("%lld\n" , ans * k % mod);
	}
	return 0;
}
/*
*/