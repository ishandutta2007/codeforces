#include <bits/stdc++.h>
using namespace std;
int n , m , x;
long long dp[3300000][4] , fac[3300000] , inv[3300000] , inc[3300000];
const int mod = 1e9 + 7 , inv3 = 333333336;
void init()
{
	fac[0] = inv[0] = inv[1] = inc[0] = 1;
	for(int i = 1 ; i <= 3000000 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 3000000 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1 ; i <= 3000000 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
	return ;
}
long long C( int a , int b )
{
	if(a < b || b < 0) return 0;
	return fac[a] * inc[b] % mod * inc[a - b] % mod; 
}
int main()
{
	init();
	scanf("%d%d" , &n , &m);
	dp[0][0] = dp[0][1] = dp[0][2] = n;
	for(int i = 1 ; i <= 3 * n ; i++ )
	{
		dp[i][0] = ((C(3 * n , i + 1) % mod - 2 * dp[i - 1][0] - dp[i - 1][1]) % mod + mod) * inv3 % mod;
		dp[i][1] = (dp[i][0] + dp[i - 1][0]) % mod;
		dp[i][2] = (dp[i][1] + dp[i - 1][1]) % mod;
//		cerr << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
	}
	while(m--)
	{
		scanf("%d" , &x);
		printf("%lld\n" , (dp[x][0] + C(3 * n , x)) % mod);
	}
	return 0;
}
/*

*/