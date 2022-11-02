#include<bits/stdc++.h>
using namespace std;
int n , a[3300] , b[3300] , s , t , dis[3300] , cur[3300] , f[110];
int fst[880000] , nex[880000] , v[880000] , val[880000] , tot = -1;
long long ans;
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
}
bool bfs()
{
	memset(dis , 0 , sizeof(dis));
	bool flag = 0; 
	queue< int > q;
	q.push(s); dis[s] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == t) flag = 1;
		for(int i = fst[u] ; ~i ; i = nex[i] )
			if(val[i] && !dis[v[i]]) dis[v[i]] = dis[u] + 1 , q.push(v[i]);
	}
	return flag;
}
int dfs( int u , int flow )
{
	if(u == t) 
	{
		ans -= flow;
		return flow;
	}
	int q = flow;
	for( ; ~cur[u] ; cur[u] = nex[cur[u]] ) 
	{
		int i = cur[u];
		if(dis[v[i]] == dis[u] + 1)
		{
			int qwq = dfs(v[i] , min(flow , val[i]));
			flow -= qwq; val[i] -= qwq; val[i ^ 1] += qwq;
			if(flow <= 0) break;
		}
	}
	return q - flow;
}
void dinic()
{
	while(bfs())
	{
		for(int i = s ; i <= t ; i++ ) cur[i] = fst[i];
		dfs(s , 1e9);
	}
	return ;
}
int main()
{
	memset(fst , -1 , sizeof(fst));
	scanf("%d" , &n); s = 0; t = n + 1;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &b[i]);
	for(int i = 1 ; i <= n ; i++ )
	{
		if(b[i] > 0) add(s , i , b[i]) , add(i , s , 0) , ans += b[i]; 
		else add(i , t , -b[i]) , add(t , i , 0); 
		memset(f , 0 , sizeof(f));
		for(int j = i - 1 ; j >= 1 ; j-- )
		{
			if(a[i] % a[j] == 0)
			{
				if(!f[a[j]])
				{
					add(i , j , 1e9) , add(j , i , 0); 
					f[a[j]] = 1;
				}
			}
		}
	}
	dinic();
	printf("%lld" , ans);
	return 0;
}
/*
20
7 3 3 6 8 5 3 3 2 7 2 9 1 1 8 1 8 2 10 4
1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 -1 -1 -1 1 1 1 1


ans = 5
*/