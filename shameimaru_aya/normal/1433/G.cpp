#include <bits/stdc++.h>
using namespace std;
struct item
{
	int id , num;
	bool operator < ( const item &x ) const
	{
		return num > x.num;
	}
};
int n , m , k , dis[1100][1100] , vis[1100] , s[1100] , t[1100] , ans = 1e9 , sum;
int fst[1100] , nex[2200] , v[2200] , val[2200] , tot , x[1100] , y[1100] , z[1100];
priority_queue< item > q;
inline void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
}
inline void dij( int s )
{
	memset(vis , 0 , sizeof(vis));
	q.push((item){s , 0}); dis[s][s] = 0;
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(!vis[v[i]] && dis[s][v[i]] > dis[s][u] + val[i])
			{
				dis[s][v[i]] = dis[s][u] + val[i];
				q.push((item){v[i] , dis[s][v[i]]});
			}
		}
	}
	return ;
}
int main()
{
	memset(dis , 0x7f / 3 , sizeof(dis));
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &x[i] , &y[i] , &z[i]);
		add(x[i] , y[i] , z[i]); add(y[i] , x[i] , z[i]);
	}
	for(int i = 1 ; i <= k ; i++ ) scanf("%d%d" , &s[i] , &t[i]);
	for(int i = 1 ; i <= n ; i++ ) dij(i);
	for(int i = 1 ; i <= m ; i++ )
	{
		sum = 0;
		for(int j = 1 ; j <= k ; j++ )
			sum += min(dis[s[j]][t[j]] , min(dis[s[j]][x[i]] + dis[y[i]][t[j]] , dis[s[j]][y[i]] + dis[x[i]][t[j]]));
		ans = min(ans , sum);
	}
	printf("%d" , ans);
	return 0;
}
/*

*/