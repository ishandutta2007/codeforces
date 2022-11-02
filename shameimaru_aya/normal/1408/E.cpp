#include <bits/stdc++.h>
using namespace std;
struct item
{
	long long id , num;
	bool operator < ( const item &x ) const
	{
		return num < x.num;
	} 
};
int n , m , a[110000] , b[110000] , s , k , x , dis[220000] , vis[220000];
int fst[220000] , nex[660000] , v[660000] , tot;
long long ans , val[660000];
priority_queue< item > q;
inline void add( int a , int b , int c )
{
	nex[++tot] = fst[a] , fst[a] = tot;
	v[tot] = b , val[tot] = c;
}
int main()
{
	memset(dis , -0x7f / 3 , sizeof(dis));
	scanf("%d%d" , &n , &m); 
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]);
	for(int i = 1 ; i <= n ; i++ ) add(s , i , 0) , add(i , s , 0);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d" , &k);
		for(int j = 1 ; j <= k ; j++ )
		{
			scanf("%d" , &x);
			add(i , x + n , a[i] + b[x]) , add(x + n , i , a[i] + b[x]);
			ans += a[i] + b[x];
		}
	}
	q.push((item){s , 0}); dis[s] = 0;
	while(!q.empty())
	{
		long long u = q.top().id , qwq = q.top().num; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
//		cerr << u << endl;
		ans -= qwq;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
//			cerr << v[i] << ' ';
//			cerr << dis[v[i]] << ' ' <<  val[i] << endl;
			if(!vis[v[i]] && dis[v[i]] < val[i])
			{
				dis[v[i]] = val[i];
				q.push((item){v[i] , dis[v[i]]});
			}
		}
//		cerr << endl;
	}
	printf("%lld" , ans);
	return 0;
}
/*

*/