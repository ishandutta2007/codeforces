#include <bits/stdc++.h>
using namespace std;
int n , mod , pr[440000] , ispr[4400000] , cnt , tot , num[1100] , nnum[1100] , a[4400000];
void dfs( int u , int s , int k )
{
	if(u > tot)
	{
		if(s == k) return ;
		a[k] += a[s]; a[k] = (a[k] >= mod ? a[k] - mod : a[k]);
		a[k] += mod - a[s - 1]; a[k] = (a[k] >= mod ? a[k] - mod : a[k]);
		return ;
	}
	for(int i = 0 ; i <= nnum[u] ; i++ ) dfs(u + 1 , s , k) , s *= num[u];
} 
int main()
{
	for(int i = 2 ; i <= 4000000 ; i++ )
	{
		if(!ispr[i]) pr[++cnt] = i;
		for(int j = 1 ; j <= cnt && i * pr[j] <= 4000000 ; j++ )
		{
			ispr[i * pr[j]] = 1;
			if(i % pr[j] == 0) break;
		}
	}
	cin >> n >> mod; a[1] = 1; a[2] = 2;
	for(int i = 3 ; i <= n ; i++ )
	{
		int qwq = i; tot = 0; a[i] = (a[i - 1] + a[i - 1]) % mod;
		for(int j = 1 ; pr[j] * pr[j] <= i ; j++ )
		{
			if(qwq % pr[j] == 0) num[++tot] = pr[j] , nnum[tot] = 0;
			while(qwq % pr[j] == 0) qwq /= pr[j] , nnum[tot]++;
		}
		if(qwq != 1) num[++tot] = qwq , nnum[tot] = 1;
		dfs(1 , 1 , i);
	}
	printf("%d" , a[n]);
	return 0;
}
/*
4000000 998244353
*/