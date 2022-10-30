#include<bits/stdc++.h>
using namespace std;
int n , m , a[1100] , s , t , x , y , vis[1100] , dep[1100];
int fst[1100] , nex[6600] , v[6600] , val[6600] , cst[6600] , cur[1100] , tot = 1;
long long dis[1100];
queue< int > q;
void add( int a , int b , int c , int d )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c; cst[tot] = d;
	nex[++tot] = fst[b]; fst[b] = tot;
	v[tot] = a; val[tot] = 0; cst[tot] = -d;
}
int spfa()
{
	memset(dep , 0 , sizeof(dep));
	memset(dis , -0x7f / 3 , sizeof(dis)); memset(vis , 0 , sizeof(vis));
	q.push(s); vis[s] = 1; dis[s] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(!val[i]) continue;
			if(dis[v[i]] < dis[u] + cst[i])
			{
				dis[v[i]] = dis[u] + cst[i]; dep[v[i]] = dep[u] + 1;
				if(!vis[v[i]]) q.push(v[i]) , vis[v[i]] = 1;
			}
		}
	}
	return dis[t] > 0;
}
int dfs( int u , int flow )
{
	if(u == t) return flow;
	int sum = 0;
	for(int &i = cur[u] ; i ; i = nex[i] )
	{
		if(dep[u] + 1 != dep[v[i]] || dis[u] + cst[i] != dis[v[i]] || !val[i]) continue;
		int qwq = dfs(v[i] , min(flow , val[i]));
		sum += qwq; flow -= qwq; val[i] -= qwq; val[i ^ 1] += qwq;
	}
	return sum;
}
void dinic()
{
	while(spfa())
	{
//		cerr << dis[t] << endl;
		memcpy(cur , fst , sizeof(cur));
		dfs(s , 1e9);
	}
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d" , &n , &m); s = 0; t = n + 1;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= n ; i++ ) add(s , i , 1 , 0) , add(i , t , 1 , 0);
	for(int i = 1 ; i <= m ; i++ ) 
		scanf("%d%d" , &x , &y) , add(x , y , 1e9 , a[x] - a[y]); 
	dinic(); spfa();
	for(int i = 1 ; i <= n ; i++ ) printf("%lld " , a[i] + dis[i]);
    return 0;
}
/*
*/