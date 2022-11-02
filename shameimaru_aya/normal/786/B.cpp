#include<bits/stdc++.h>
#define lson (Id << 1)
#define rson (Id << 1 | 1)
using namespace std;
int n , m , rt , opt , a , b , c , d , id[2][110000] , t[2] , vis[880000];
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
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	return ;
}
void build( int l , int r , int Id )
{
	if(l == r) 
	{
		add(Id + (n << 2) , Id , 0);
		return ;
	}
	add(lson , Id , 0); add(rson , Id , 0); 
//	cerr << Id << ' ' << lson << ' ' << rson << endl;
	add(Id + (n << 2) , lson + (n << 2) , 0);
	add(Id + (n << 2) , rson + (n << 2) , 0);
	int mid = l + r >> 1;
	build(l , mid , lson);
	build(mid + 1 , r , rson);
	return ;
}
void getid( int l , int r , int a , int b , int tp , int Id )
{
	if(r < a || b < l) return ;
	if(a <= l && r <= b)
	{
		id[tp][++t[tp]] = Id + tp * (n << 2);
		return ;
	}
	int mid = l + r >> 1;
	getid(l , mid , a , b , tp , lson);
	getid(mid + 1 , r , a , b , tp , rson);
	return ;
}
void dij( int s )
{
	memset(dis , 0x7f / 3 , sizeof(dis));
	priority_queue< item > q;
	q.push((item){s , 0});
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
//		cerr << u << ' ' << dis[u] << endl;
		for(int i = fst[u] ; i  ; i = nex[i] )
		{
			if(dis[v[i]] > dis[u] + val[i])
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
	scanf("%d%d%d" , &n , &m , &rt);
	build(1 , n , 1);
	while(m--)
	{
		scanf("%d%d%d%d" , &opt , &a , &b , &c);
		t[0] = t[1] = 0;
		if(opt == 1)
		{
			getid(1 , n , a , a , 0 , 1);
			getid(1 , n , b , b , 1 , 1);
			add(id[0][1] , id[1][1] , c);
		}
		if(opt == 2)
		{
			scanf("%d" , &d);
			getid(1 , n , a , a , 0 , 1);
			getid(1 , n , b , c , 1 , 1);
			for(int i = 1 ; i <= t[1] ; i++ ) add(id[0][1] , id[1][i] , d);
		}
		if(opt == 3)
		{
			scanf("%d" , &d);
			getid(1 , n , a , a , 1 , 1);
			getid(1 , n , b , c , 0 , 1);
			for(int i = 1 ; i <= t[0] ; i++ ) add(id[0][i] , id[1][1] , d);
		}
	}
	t[0] = t[1] = 0;
	getid(1 , n , rt , rt , 0 , 1);
	dij(id[0][1]);
	for(int i = 1 ; i <= n ; i++ )
	{
		if(i == rt)
		{
			printf("0 ");
			continue;
		}
		t[0] = 0;
		getid(1 , n , i , i , 0 , 1);
//		cerr << vis[id[0][1] + (n << 2)] << ' ';
		if(vis[id[0][1] + (n << 2)]) printf("%lld " , dis[id[0][1] + (n << 2)]);
		else printf("-1 ");
	}
	return 0;
}
/*
85 1 1
1 1 85 153155
*/