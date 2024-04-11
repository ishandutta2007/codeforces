#include <bits/stdc++.h> 
using namespace std;
int n , m , a[4400] , siz[4400] , ls[4400] , rs[4400] , rt;
long long dp[4400][4400] , sav[4400];
stack< int > s;
void dfs( int u )
{
	memset(dp[u] , -0x7f / 3 , sizeof(dp[u]));
	dp[u][1] = 0; dp[u][0] = 0; siz[u] = 1;
	if(ls[u])
	{
		dfs(ls[u]); memcpy(sav , dp[u] , sizeof(sav)); 
		for(int i = 0 ; i <= siz[u] ; i++ ) 
			for(int j = 0 ; j <= siz[ls[u]] ; j++ ) 
				dp[u][i + j] = max(dp[u][i + j] , sav[i] + dp[ls[u]][j] + 1ll * j * (m - j) * (a[ls[u]] - a[u]));
		siz[u] += siz[ls[u]];
	}
	if(rs[u])
	{
		dfs(rs[u]); memcpy(sav , dp[u] , sizeof(sav)); 
		for(int i = 0 ; i <= siz[u] ; i++ ) 
			for(int j = 0 ; j <= siz[rs[u]] ; j++ ) 
				dp[u][i + j] = max(dp[u][i + j] , sav[i] + dp[rs[u]][j] + 1ll * j * (m - j) * (a[rs[u]] - a[u]));
		siz[u] += siz[rs[u]];
	}
	return ;
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= n ; i++ )
	{
		while(!s.empty())
		{
			if(a[s.top()] > a[i]) ls[i] = s.top() , s.pop();
			else break;
		}
		if(!s.empty()) rs[s.top()] = i;
		else rt = i;
		s.push(i);
	}
	dfs(rt);
	printf("%lld" , dp[rt][m]);
	return 0;
}
/*
6 2
15 2 18 12 13 4

*/