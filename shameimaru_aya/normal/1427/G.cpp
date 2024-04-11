#include <bits/stdc++.h>
using namespace std;
int n , r , c , a[220][220] , p[1000] , flag , plx[1000] , ply[1000];
int k , s , t , num[44000] , dis[44000] , vis[44000];
int fst[44000] , nex[2000000] , v[2000000] , val[2000000] , tot = 1;
long long ans , mf;
void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	nex[++tot] = fst[b]; fst[b] = tot;
	v[tot] = a; val[tot] = 0;
}
int dfs( int u , int flow )
{
	if(u == t)
	{
		mf += flow; flag = 1;
		return flow;
	}
	vis[u] = 1;
	for(int i = fst[u] ; i && !flag ; i = nex[i] )
	{
		if(val[i] && !vis[v[i]])
		{
			int qwq = dfs(v[i] , min(val[i] , flow));
			if(flag)
			{
				val[i] -= qwq; val[i ^ 1] += qwq;
				return qwq;
			}
		}
	}
	return 0;
}
void FF()
{
	memset(vis , 0 , sizeof(vis));
	flag = 0; dfs(s , 1e9);
	while(flag)
	{
		memset(vis , 0 , sizeof(vis));
		flag = 0; dfs(s , 1e9);
	}
	return ;
}
void idfs( int u )
{
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(val[i] && (i & 1))
		{
			val[i]--; val[i ^ 1]++;
			idfs(v[i]);
			return ;
		}
	}
}
inline int id( int x , int y )
{
	return (x - 1) * c + y;
}
int main()
{
	scanf("%d" , &r); c = r;
	for(int i = 1 ; i <= r ; i++ )
		for(int j = 1 ; j <= c ; j++ ) scanf("%d" , &a[i][j]);
	for(int i = 1 ; i <= c ; i++ ) 
		p[++k] = a[1][i] , plx[k] = 1 , ply[k] = i , p[++k] = a[r][i] , plx[k] = r , ply[k] = i;
	for(int i = 2 ; i < r ; i++ ) 
		p[++k] = a[i][1] , plx[k] = i , ply[k] = 1 , p[++k] = a[i][c] , plx[k] = i , ply[k] = c;
	n = k; memcpy(num , p , sizeof(num));
	sort(p + 1 , p + k + 1); k = unique(p + 1 , p + k + 1) - p - 1;
	s = 0; t = r * c + 1;
	for(int i = 1 ; i < c ; i++ ) 
		for(int j = 1 ; j <= r ; j++ )
			if(~a[j][i] && ~a[j][i + 1])
				add(id(j , i) , id(j , i + 1) , 1) , add(id(j , i + 1) , id(j , i) , 1);
	for(int i = 1 ; i < r ; i++ ) 
		for(int j = 1 ; j <= c ; j++ )
			if(~a[i][j] && ~a[i + 1][j])
				add(id(i , j) , id(i + 1 , j) , 1) , add(id(i + 1 , j) , id(i , j) , 1);
	for(int i = 1 ; i <= n ; i++ ) 
		add(id(plx[i] , ply[i]) , t , 1e9);
	for(int i = 1 ; i < k ; i++ )
	{
		for(int j = 1 ; j <= n ; j++ ) 
		{
			if(num[j] == p[i])
			{
				int e;
				for(int qwq = fst[t] ; qwq ; qwq = nex[qwq] )
					if(v[qwq] == id(plx[j] , ply[j])) { e = qwq; break; }
//				cerr << v[e] << ' ' << v[e ^ 1] << ' ' << val[e] << endl;
				while(val[e]) val[e]-- , idfs(id(plx[j] , ply[j])) , mf--;
				val[e ^ 1] = 0;
				add(s , id(plx[j] , ply[j]) , 1e9);
			}
		}
		flag = 1;
		while(flag) flag = 0 , FF();
		ans += mf * (p[i + 1] - p[i]);
//		cerr << mf << endl; 
	}
	printf("%lld" , ans);
	return 0;
}
/*
3 3 
1 7 6
4 0 6
1 1 1

3 3 
10 100 1
1 -1 100
10 10 10

*/