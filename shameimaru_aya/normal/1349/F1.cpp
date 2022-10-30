#include <bits/stdc++.h>
using namespace std;
int n;
long long S[5100][5100] , fac[5500] , inv[5500] , inc[5500] , sum[5500] , ans;
const int mod = 998244353;
void init()
{
	S[1][1] = S[0][0] = 1;
	for(int i = 2 ; i <= 5000 ; i++ )
		for(int j = 1 ; j <= 5000 ; j++ ) S[i][j] = (S[i - 1][j] * j % mod + S[i - 1][j - 1]) % mod;
	fac[0] = 1; inv[0] = inv[1] = inc[0] = 1;
	for(int i = 1 ; i <= 5000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 5000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1 ; i <= 5000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
}
long long C( int a , int b )
{
	if(a < b || b < 0) return 0;
	return fac[a] * inc[a - b] % mod * inc[b] % mod;
}
int main()
{
	init();
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
		for(int j = 0 ; j < n ; j++ ) 
			sum[j] = (sum[j] + S[i][i - j] * fac[i - j] % mod * fac[n] % mod * inc[i] % mod) % mod;
	for(int j = 0 ; j < n ; j++ )
	{
		ans = 0;
		for(int k = j ; k < n ; k++ )
			(ans += (k - j & 1 ? mod - 1 : 1) * C(k , j) % mod * sum[k] % mod) %= mod;
		printf("%lld " , ans);
	}
	return 0;
}
/*
*/