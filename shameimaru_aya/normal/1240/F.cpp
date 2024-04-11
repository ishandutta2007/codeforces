#include <bits/stdc++.h>
using namespace std;
int n , m , k , du[2][1100] , c[44000][1100] , u[11000] , v[11000] , id[2][1100] , cnt , ans[22000];
void gogo( int x , int y , int id , int c1 = 0 , int c2 = 0 )
{
	for(int i = 1 ; i <= k ; i++ )
	{
		if(c1 && i != c1) continue;
		if(!c[x][i] && !c[y][i]) 
		{
			ans[id] = i;
			c[x][i] = c[y][i] = id;
//			cerr << i << ' ' << id << ' ' << x << ' ' << y << endl;
			return ;
		}
	}
	if(!c1 && !c2)
	{
		for(int i = 1 ; i <= k ; i++ )
		{
			if(!c[x][i])
			{
				c1 = i; break;
			}
		}
		for(int i = 1 ; i <= k ; i++ )
		{
			if(!c[y][i])
			{
				c2 = i; break;
			}
		}	
	}
//	cerr << x << ' ' << y << ' ' << c1 << ' ' << c2 << ' ' << c[x][c1] << ' ' << c[y][c1] << endl;
	int e = c[y][c1]; c[y][c1] = c[x][c1] = id; c[u[e] + v[e] - y][c1] = 0; ans[id] = c1; 
	gogo(y , u[e] + v[e] - y , e , c2 , c1);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &u[0]);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &u[i] , &v[i]);
		du[0][u[i]]++; du[1][v[i]]++; 
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		id[0][i] = ++cnt;
		while(du[0][i] > k) ++cnt , du[0][i] -= k;
		du[0][i] = 0;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		id[1][i] = ++cnt;
		while(du[1][i] > k) ++cnt , du[1][i] -= k;
		du[1][i] = 0;
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		int qwq = u[i] , qaq = v[i];
		u[i] = id[0][u[i]] , v[i] = id[1][v[i]]; 
		gogo(u[i] , v[i] , i);
		du[0][qwq]++; du[1][qaq]++; 
		if(du[0][qwq] == k) du[0][qwq] = 0 , id[0][qwq]++;
		if(du[1][qaq] == k) du[1][qaq] = 0 , id[1][qaq]++;
//		cerr << id[0][u[i]] << ' ' << id[1][v[i]] << endl;
	}
	for(int i = 1 ; i <= m ; i++ ) printf("%d\n" , ans[i]);
	return 0;
}
/*
gogo!
*/