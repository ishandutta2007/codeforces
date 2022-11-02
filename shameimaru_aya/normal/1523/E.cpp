#include <bits/stdc++.h>
using namespace std;
int n , m , T;
long long fac[110000] , inv[110000] , inc[110000] , s , ans;
const int mod = 1e9 + 7;
void init()
{
	fac[0] = inv[1] = inv[0] = inc[0] = inc[1] = 1;
	for(int i = 1 ; i <= 100000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 100000 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= 100000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
inline long long C( long long a , long long b )
{
	if(b < 0 || a < b) return 0;
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
int main()
{
	init();
	scanf("%d" , &T);
	while(T--)
	{
		ans = 1; s = 1;
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ )
		{
			s = s * i % mod * inv[n - i + 1] % mod;
			ans = (ans + s * C(n - 1ll * (i - 1) * (m - 1) , i) % mod) % mod;
		}
		printf("%lld\n" , ans);
	}
	
	return 0;
}
/*
*/