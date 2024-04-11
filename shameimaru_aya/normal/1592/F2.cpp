#include <bits/stdc++.h> 
using namespace std;
int n , m , a[550][550] , b[550][550] , ans , mf , s , t , cur[1100] , dis[1100] , flag;
int fst[1100] , nex[1100000] , v[1100000] , val[1100000] , tot = 1;
string str;
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	nex[++tot] = fst[b]; fst[b] = tot;
	v[tot] = a; val[tot] = 0;
}
bool bfs()
{
	memset(dis , 0 , sizeof(dis));
	queue< int > q; q.push(s); dis[s] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(val[i] && !dis[v[i]])
			{
				dis[v[i]] = dis[u] + 1;
				q.push(v[i]);
			}
		}
	}
	return dis[t] != 0;
}
int dfs( int u , int flow )
{
	if(u == t)
	{
		mf += flow;
		return flow;
	}
	int sum = 0;
	for( ; cur[u] ; cur[u] = nex[cur[u]] )
	{
		int i = cur[u];
		if(dis[v[i]] != dis[u] + 1 || !val[i]) continue;
		int qwq = dfs(v[i] , min(flow , val[i]));
		flow -= qwq; sum += qwq; val[i] -= qwq; val[i ^ 1] += qwq;
	}
	return sum;
}
void dinic()
{
	while(bfs())
	{
		memcpy(cur , fst , sizeof(cur));
		dfs(s , 1e9);
	}
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		cin >> str;
		for(int j = 1 ; j <= m ; j++ ) a[i][j] = (str[j - 1] == 'B');
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ )
			b[i][j] = a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1] , ans += b[i][j];
	}
	s = 0; t = n + m + 1;
	for(int i = 1 ; i < n ; i++ )
		for(int j = 1 ; j < m ; j++ )
			if(b[i][j] && b[n][j] && b[i][m]) add(i , j + n , 1);
//	for(int i = 1 ; i <= n ; i++ )
//	{
//		for(int j = 1 ; j <= m ; j++ ) cerr << b[i][j] << ' ';
//		cerr << endl;
//	}
	for(int i = 1 ; i <= n ; i++ ) add(s , i , 1);
	for(int i = 1 ; i <= m ; i++ ) add(i + n , t , 1);
	dinic();
	if((mf & 1) == b[n][m]) ans -= (mf + 1) / 2 * 2;
	else ans -= mf / 2 * 2;
	printf("%d" , ans);
	return 0;
}
/*
*/