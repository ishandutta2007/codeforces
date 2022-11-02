#include<bits/stdc++.h>
using namespace std;
int n , m , a;
long long ans , sum , fac[440000] , inv[440000] , inc[440000];
const int mod = 1e9 + 7;
inline void init()
{
	fac[0] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 1 ; i <= 400000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 400000 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= 400000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
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
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a) , sum += a;
	sum %= mod;
	if(n == 1) 
	{
		printf("%lld" , sum);
		return 0;
	}
	for(int i = 0 ; i < m ; i++ )
		ans += ((m - i - 1) % 2 ? -1 : 1) * inc[m - i - 1] * inc[i] % mod * (n + i) % mod * exp(i + 1 , n - 2) % mod;
	printf("%lld" , (ans % mod + mod) % mod * sum % mod);
	return 0;
}
/*
*/