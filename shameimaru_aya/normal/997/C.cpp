#include<bits/stdc++.h>
using namespace std;
long long n , p3[2200000] , p3n[2200000] , ans , fac[1100000] , inv[1100000] , inc[1100000];
const int mod = 998244353 , inv3 = 332748118;
inline void init()
{
	fac[0] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 1 ; i <= 1000000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= 1000000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
inline long long exp( long long a , long long b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod; b >>= 1;
	}
	return ans;
}
inline long long C( int a , int b )
{
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
int main()
{
	init();
	scanf("%lld" , &n); 
	for(int i = 1 ; i <= n ; i++ )
		ans += 2 * ((i & 1) ? 1 : -1) * exp(3 , n * n - i * n + i) * C(n , i) % mod;
	for(int i = 1 ; i <= n ; i++ )
	{
		ans += exp(3 , n * n + 1 - i * n) * ((i & 1) ? 1 : -1) * C(n , i) % mod
			 * (exp(1 - exp(inv3 , n - i) , n) - 1) % mod;
	}
	printf("%lld" , (ans % mod + mod) % mod);
	return 0;
}
/*
*/