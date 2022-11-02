#include <bits/stdc++.h>
using namespace std;
int n , s , t , dis[2200] , cur[2200];
int fst[2200] , nex[2200000] , v[2200000] , val[2200000] , tot = 1;
long long sum = 0 , mf;
struct item
{
	int x , y , w , id;
} node[1100];
int id( int x , int y )
{
	if(x % 2 && y % 2 == 0) return 0;
	if(x % 2 == 0 && y % 2 == 0) return 1;
	if(x % 2 == 0 && y % 2) return 2;
	return 3;
}
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	nex[++tot] = fst[b] , fst[b] = tot;
	v[tot] = a , val[tot] = 0;
}
bool bfs()
{
	queue< int > q;
	bool flag = 0;
	q.push(s); dis[s] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == t) flag = 1;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(val[i] && !dis[v[i]])
			{
//				cerr << u << ' ' << v[i] << endl;
				dis[v[i]] = dis[u] + 1;
				q.push(v[i]);
			}
		}
	}
	return flag;
}
int dfs( int u , long long flow )
{
	if(u == t)
	{
		mf += flow;
		return flow;
	}
	long long sum = 0;
	for( ; cur[u] ; cur[u] = nex[cur[u]] )
	{
		int i = cur[u];
		if(dis[v[i]] != dis[u] + 1 || !val[i]) continue;
		long long qwq = dfs(v[i] , min(flow , (long long)val[i]));
		flow -= qwq; sum += qwq; val[i] -= qwq; val[i ^ 1] += qwq;
	}
	return sum;
}
void dinic()
{
	mf = 0;
	memset(dis , 0 , sizeof(dis));
	while(bfs())
	{
		memcpy(cur , fst , sizeof(cur));
		dfs(s , 1e18);
		memset(dis , 0 , sizeof(dis));
	}
	return ;
}
int main()
{
	scanf("%d" , &n); s = 0; t = 2 * n + 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d%d" , &node[i].x , &node[i].y , &node[i].w);
		node[i].id = id(node[i].x , node[i].y); sum += node[i].w;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		if(node[i].id == 0) add(s , i , 1e9);
		if(node[i].id == 3) add(i + n , t , 1e9);
		add(i , i + n , node[i].w);
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = i + 1 ; j <= n ; j++ )
		{
			if(abs(node[i].x - node[j].x) + abs(node[i].y - node[j].y) == 1
			&& abs(node[i].id - node[j].id) == 1)
			{
				if(node[i].id < node[j].id) add(i + n , j , 1e9);
				else add(j + n , i , 1e9);
			}
		}
	}
	dinic();
	printf("%lld" , sum - mf);
	return 0;
}
/*
*/