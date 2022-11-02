#include <bits/stdc++.h>
using namespace std;
int n , m , l[60] , r[60] , p[120];
long long C[60] , dp[130][60] , inv[60] , ans , s = 1;
const int mod = 998244353;
void init()
{
	inv[0] = inv[1] = 1;
	for(int i = 2 ; i <= 50 ; i++ ) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	return ;
}
long long exp( int a , int b )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1) ans = ans * t % mod;
		t = t * t % mod; b >>= 1;
	}
	return ans;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	init();
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d%d" , &l[i] , &r[i]) , l[i]-- , s = s * (r[i] - l[i]) % mod;
		p[2 * i - 1] = l[i] , p[2 * i] = r[i];
	}
	sort(p + 1 , p + n * 2 + 1); m = unique(p + 1 , p + 2 * n + 1) - p - 1;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		l[i] = lower_bound(p + 1 , p + m + 1 , l[i]) - p;
		r[i] = lower_bound(p + 1 , p + m + 1 , r[i]) - p;
	}
//	cerr << endl;
	dp[m][0] = 1;
	for(int i = m - 1 ; i >= 1 ; i-- )
	{
//		cerr << p[i] << ' ' << p[i + 1] << endl;
		C[0] = 1;
		for(int j = 1 ; j <= n ; j++ ) 
			C[j] = C[j - 1] * (p[i + 1] - p[i] + j - 1) % mod * inv[j] % mod;
		for(int j = 0 ; j <= n ; j++ )
		{
			(dp[i][j] += dp[i + 1][j]) %= mod;
			for(int k = j + 1 ; k <= n ; k++ )
			{
				if(l[k] > i || r[k] < i + 1) break;
				(dp[i][k] += dp[i + 1][j] * C[k - j] % mod) %= mod;
			}
		}
//		cerr << dp[i][n] << endl;
	}
//	cerr << dp[1][n] << ' ' << s << endl;
	printf("%lld" , dp[1][n] * exp(s , mod - 2) % mod);
	return 0;
}
/*
*/