#include<bits/stdc++.h>
using namespace std;
int n;
long long m , a[30] , inv = 1 , qwq , num , ans;
const int mod = 1e9 + 7;
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
inline long long C( long long a , long long b ) 
{
	if(a < b || a < 0 || b < 0) return 0;
	long long ans = 1;
	for(long long i = a ; i >= a - b + 1 ; i-- ) ans = ans * (i % mod) % mod;
	return ans * inv % mod;
}
int main()
{
	scanf("%d%lld" , &n , &m);
	for(int i = 1 ; i < n ; i++ ) inv = inv * exp(i , mod - 2) % mod;
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &a[i]);
	for(int i = 0 ; i < (1 << n) ; i++ )
	{
		qwq = 1; num = 1;
		for(int j = 0 ; j < n ; j++ )
			if(i & (1 << j)) qwq *= -1 , num += a[j + 1] + 1;
		ans = ((ans + qwq * C(m + n - num , n - 1)) % mod + mod) % mod;
	}
	printf("%d" , ans);
    return 0;
}