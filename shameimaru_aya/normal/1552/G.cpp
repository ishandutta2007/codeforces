#include <bits/stdc++.h>
using namespace std;
int n , m , num[20] , a[20][40] , vis[20][40] , newnum[20] , gg;
long long al;
//map< long long , int > mp[20];
void dfs( int u , long long msk )
{
	if(gg) return ;
//	mp[u][msk] = 1;
	if(u == m)
	{
//		cerr << msk << endl;
		int f = 0;
		for(int i = 0 ; i < n ; i++ )
		{
			if(!f && ((msk >> i) & 1)) f = 1;
			if(f && !((msk >> i) & 1)) f = 2;
		}
		if(f == 2) gg = 1;
		return ;
	}
	int t0 = 0 , t1 = 0 , t2 = 0; long long qwq = al;
	for(int i = 1 ; i <= num[u + 1] ; i++ )
	{
		qwq ^= (1ll << a[u + 1][i]);
		if(!vis[u][a[u + 1][i]]) t2++;
		else 
		{
			if((msk >> a[u + 1][i]) & 1) t1++;
			else t0++;
		}
	}
	long long vmsk = msk & qwq;
	for(int j = t0 + t2 + 1 ; j <= num[u + 1] ; j++ ) vmsk |= (1ll << a[u + 1][j]);
	for(int i = t2 ; i >= 0 ; i-- )
	{
		dfs(u + 1 , vmsk);
		vmsk |= (1ll << a[u + 1][t0 + i]);
	}
}
int main() 
{
	scanf("%d%d" , &n , &m); al = (1ll << n) - 1;
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d" , &num[i]);
		memcpy(vis[i] , vis[i - 1] , sizeof(vis[i]));
		for(int j = 1 ; j <= num[i] ; j++ ) 
		{
			scanf("%d" , &a[i][j]); a[i][j]--;
			vis[i][a[i][j]] = 1;
		}
	}
	if(n == 1)
	{
		printf("ACCEPTED");
		return 0;
	}
	for(int i = 0 ; i < n ; i++ ) 
	{
		if(!vis[m][i])
		{
			printf("REJECTED");
			return 0;
		}
	}
	dfs(0 , 0);
	if(gg) printf("REJECTED");
	else printf("ACCEPTED");
    return 0;
}