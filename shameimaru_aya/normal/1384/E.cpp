#include<bits/stdc++.h>
using namespace std;
int T , n , isdag[1100000] , siz[1100000] , maxx = 1 << 20;
int num , reach[30] , ans , vis[30];
string a , b; 
void dfs( int u )
{
	vis[u] = 1;
	for(int i = 0 ; i < 20 ; i++ )
	{
		if(((reach[u] & (1 << i)) || (reach[i] & (1 << u))) && !vis[i]) dfs(i);
	}
	return ;
}
int main()
{
	for(int i = 0 ; i < maxx ; i++ )
		for(int j = 0 ; j <= 19 ; j++ )
			if((i | (1 << j)) != i) siz[i | (1 << j)] = siz[i] + 1;
	isdag[0] = 1;
	scanf("%d" , &T);
	while(T--)
	{
		memset(reach , 0 , sizeof(reach)); memset(vis , 0 , sizeof(vis));
		ans = 0; num = 0;
		scanf("%d" , &n); cin >> a >> b;
		for(int i = 0 ; i < n ; i++ ) reach[a[i] - 'a'] |= 1 << (b[i] - 'a');
		for(int i = 0 ; i < 20 ; i++ )
		{
			if(!vis[i]) dfs(i) , num++;
		}
		for(int i = 1 ; i < maxx ; i++ )
		{
//			cerr << i << endl;
			if(isdag[i]) isdag[i] = 0;
			for(int j = 0 ; j < 20 ; j++ )
			{
				int qwq = i ^ (1 << j);
				if((i & (1 << j))) isdag[i] |= isdag[qwq] & (!(reach[j] & qwq));
			}
			if(isdag[i]) ans = max(ans , siz[i]);
		}
//		cerr << num << ' ' << ans << endl;
		printf("%d\n" , 40 - num - ans);
	}
	return 0;
}