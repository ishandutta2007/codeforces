#include <bits/stdc++.h> 
using namespace std;
int n , a[5500] , pre[5500] , noww = 1;
long long dp[5500] , sum[5500];
const int mod = 998244353;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1); a[n + 1] = 1e9;
	for(int i = 1 ; i <= n ; i++ )
	{
		while(a[noww] * 2 <= a[i]) noww++;
		pre[i] = noww - 1;
	}
	for(int i = 1 ; i <= n ; i++ ) dp[i] = 1 , sum[i] = i;
	for(int i = 1 ; i < n ; i++ )
	{
		for(int j = 1 ; j <= n ; j++ )
		{
			dp[j] = (pre[j] - i + 1) * dp[j] % mod;
			(dp[j] += sum[pre[j]]) %= mod;
//			cerr << dp[j] << ' ';
		}
		for(int j = 1 ; j <= n ; j++ ) sum[j] = (sum[j - 1] + dp[j]) % mod;
//		cerr << endl;
	}
	printf("%lld" , sum[n]);
	return 0;
}
/*

*/