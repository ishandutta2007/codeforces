#include<bits/stdc++.h>
#define ppc(x) __builtin_popcount(x)
using namespace std;
int n , m , N , a[20][20];
long long dp[1 << 18][19] , f[19][1 << 18] , g[1 << 18] , ans[1 << 18];
vector< int > msk;
map< vector< int > , long long > mp;
string s;
void FWT( long long *f , int k )
{
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j <= N ; j++ ) 
			if(j & (1 << i)) f[j] += f[j ^ (1 << i)];
}
void dfs( int s , int v )
{
	if(s == n)
	{
		long long ans = 0;
		for(int i = 0 ; i <= N ; i++ )
		{
			if((ppc(i) - ppc(N)) % 2) ans -= g[i];
			else ans += g[i];
		}
		mp[msk] = ans;
		return ;
	}
	long long sav[1 << 18];
	for(int i = v ; i <= n - s ; i++ )
	{
		for(int j = 0 ; j <= N ; j++ ) sav[j] = g[j];
		for(int j = 0 ; j <= N ; j++ ) g[j] *= f[i][j];
		msk.push_back(i);
		dfs(s + i , i);
		msk.pop_back();
		for(int j = 0 ; j <= N ; j++ ) g[j] = sav[j];
	}
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n); N = (1 << n) - 1; m = (1 << n - 1) - 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		cin >> s;
		for(int j = 0 ; j < n ; j++ ) a[i][j + 1] = s[j] - '0';
	} 
	for(int i = 1 ; i <= n ; i++ ) dp[1 << (i - 1)][i] = 1;
	for(int i = 0 ; i <= N ; i++ )
	{
		if(ppc(i) <= 1) continue;
		for(int j = 1 ; j <= n ; j++ )
		{
			if((i & (1 << (j - 1))) == 0) continue;
			for(int k = 1 ; k <= n ; k++ )
			{
				if((i & (1 << (k - 1))) == 0 || !a[j][k]) continue;
				dp[i][k] += dp[i ^ (1 << (k - 1))][j];
			}
		}
	}
	for(int i = 1 ; i <= N ; i++ )
		for(int j = 1 ; j <= n ; j++ ) f[ppc(i)][i] += dp[i][j];
	for(int i = 1 ; i <= n ; i++ ) FWT(f[i] , 1);
	g[0] = 1; FWT(g , 1);
	dfs(0 , 1);
	for(int i = 0 ; i <= m ; i++ )
	{
		int t = 1; msk.clear();
		for(int j = 0 ; j < n ; j++ )
		{
			if(i & (1 << j)) t++;
			else msk.push_back(t) , t = 1;
		}
		sort(msk.begin() , msk.end());
		ans[i] = mp[msk];
	}
	for(int i = 0 ; i < n - 1 ; i++ )
		for(int j = 0 ; j <= m ; j++ ) 
			if(!(j & (1 << i))) ans[j] -= ans[j ^ (1 << i)];
	for(int i = 0 ; i <= m ; i++ ) printf("%lld " , ans[i]);
    return 0;
}
/*
*/