#include<bits/stdc++.h>
using namespace std;
int n , m , mp[220][220] , x , y , z , mf , s , t , dis[88000] , cur[88000] , cnt;
int fst[88000] , nex[600000] , v[600000] , val[600000] , tot = -1;
int id[4][220][220] , ans; //0l 1r 2u 3d
queue< int > q;
string str;
inline void add( int a , int b , int c )
{
	nex[++tot] = fst[a] , fst[a] = tot;
	v[tot] = b , val[tot] = c;
	nex[++tot] = fst[b] , fst[b] = tot;
	v[tot] = a , val[tot] = 0;
	return ;
}
inline bool bfs()
{
	bool flag = false;
	q = queue< int >();
	q.push(s);
	dis[s] = 1;
	while(!q.empty())
	{
		int noww = q.front();
		q.pop();
		if(noww == t) flag = true;
		for(int i = fst[noww] ; ~i ; i = nex[i] )
		{
			if(val[i] && !dis[v[i]])
			{
				dis[v[i]] = dis[noww] + 1;
				q.push(v[i]);
			}
		}
	}
	return flag;
}
int dfs( int u , int flow )
{
	if(u == t) return flow;
	int sum = 0;
	for(int i = cur[u] ; ~i ; cur[u] = i , i = nex[i] )
	{
		if(!flow) break;
		if(val[i] && dis[v[i]] == dis[u] + 1)
		{
			int qwq = dfs(v[i] , min(val[i] , flow));
			val[i] -= qwq; val[i ^ 1] += qwq;
			flow -= qwq; sum += qwq;
			if(!flow) break;
		}
	}
	return sum;
}
void dinic()
{
	memset(dis , 0 , sizeof(dis));
	memcpy(cur , fst , sizeof(cur));
	while(bfs())
	{
		mf += dfs(s , 1e8);
		memset(dis , 0 , sizeof(dis));
		memcpy(cur , fst , sizeof(cur));
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	memset(fst , -1 , sizeof(fst));
	scanf("%d%d" , &n , &m); t = 80000;
	for(int i = 1 ; i <= n ; i++ )
	{
		cin >> str;
		for(int j = 1 ; j <= m ; j++ )
			if(str[j - 1] == '#') mp[i][j] = 1 , ans++;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j < m ; j++ )
		{
			if(mp[i][j] & mp[i][j + 1]) 
			{
				add(s , ++cnt , 1);
				id[3][i][j] = id[2][i][j + 1] = cnt;
			}
		}
	}
//	cerr << cnt << ' ';
	for(int i = 1 ; i < n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ )
		{
			if(mp[i][j] & mp[i + 1][j]) 
			{
				add(++cnt , t , 1);
				id[1][i][j] = id[0][i + 1][j] = cnt;
			}
		}
	}
//	cerr << cnt << endl;
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ )
		{
			if(id[0][i][j] && id[2][i][j]) add(id[2][i][j] , id[0][i][j] , 1);
			if(id[0][i][j] && id[3][i][j]) add(id[3][i][j] , id[0][i][j] , 1);
			if(id[1][i][j] && id[2][i][j]) add(id[2][i][j] , id[1][i][j] , 1);
			if(id[1][i][j] && id[3][i][j]) add(id[3][i][j] , id[1][i][j] , 1);
		}
	}
	dinic();
	printf("%d" , ans - cnt + mf);
	return 0;
}