#include<bits/stdc++.h>
using namespace std;
int n , m , x , y , z , vis[880000];
int fst[880000] , nex[4400000] , v[4400000] , val[4400000] , tot;
long long dis[880000];
struct item
{
	long long id , num;
	bool operator < ( const item &x ) const
	{
		return num > x.num;
	}
};
priority_queue< item > q;
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
}
void dij()
{
	memset(dis , 0x7f / 3 , sizeof(dis));
	q.push((item){1 , 0}); dis[1] = 0;
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(dis[u] + val[i] < dis[v[i]] && !vis[v[i]])
			{
				dis[v[i]] = dis[u] + val[i];
				q.push((item){v[i] , dis[v[i]]});
			}
		}
	}
	return ;
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z); add(y , x , z); add(x , y + n , 0); add(y , x + n , 0); 
		add(x , y + 2 * n , z + z); add(y , x + 2 * n , z + z);
		add(x , y + 3 * n , z); add(y , x + 3 * n , z); 
		add(x + n , y + n , z); add(y + n , x + n , z); 
		add(x + n , y + 3 * n , z + z); add(y + n , x + 3 * n , z + z); 
		add(x + 2 * n , y + 2 * n , z); add(y + 2 * n , x + 2 * n , z); 
		add(x + 2 * n , y + 3 * n , 0); add(y + 2 * n , x + 3 * n , 0); 
		add(x + 3 * n , y + 3 * n , z); add(y + 3 * n , x + 3 * n , z); 
	}
	dij();
	for(int i = 2 ; i <= n ; i++ ) printf("%lld " , dis[i + 3 * n]);
	return 0;
}
/*

*/