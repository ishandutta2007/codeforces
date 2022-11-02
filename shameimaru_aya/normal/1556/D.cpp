#include <bits/stdc++.h>
using namespace std;
int T , n , m , f[60][11000] , OR[11000] , AND[11000] , a[11000] , DOR , DAND , vis[11000];
queue< int > q;
int main() 
{
	T = 1;
	while(T--)
	{
		scanf("%d%d" , &n , &m); 
		for(int i = 1 ; i <= n ; i++ ) 
			for(int j = 0 ; j <= 30 ; j++ ) f[j][i] = 2;
		for(int i = 1 ; i < n ; i++ ) 
		{
			printf("and %d %d\n" , i , i + 1); fflush(stdout);
			scanf("%d" , &AND[i]);
			printf("or %d %d\n" , i , i + 1); fflush(stdout);
			scanf("%d" , &OR[i]);
		}
		printf("and 1 3\n"); fflush(stdout);
		scanf("%d" , &DAND);
		for(int i = 1 ; i <= n - 2 ; i++ )
		{
			for(int j = 0 ; j <= 30 ; j++ )
			{
				int a0 = (AND[i] >> j) & 1 , a1 = (AND[i + 1] >> j) & 1;
				if(a0 == 0 && a1 == 1)
				{
					f[j][i] = 0; f[j][i + 1] = f[j][i + 2] = 1;
				}
				if(a0 == 1 && a1 == 0)
				{
					f[j][i] = f[j][i + 1] = 1; f[j][i + 2] = 0;
				}
				if(a0 == 1 && a1 == 1)
				{
					f[j][i] = f[j][i + 1] = 1; f[j][i + 2] = 1;
				}
				if(a0 == 0 && a1 == 0)
				{
					int b0 = (OR[i] >> j) & 1 , b1 = (OR[i + 1] >> j) & 1;
					if(b0 == 0 && b1 == 0) f[j][i] = f[j][i + 1] = f[j][i + 2] = 0;
					if(b0 == 1 && b1 == 0) f[j][i] = 1 , f[j][i + 1] = f[j][i + 2] = 0;
					if(b0 == 0 && b1 == 1) f[j][i + 2] = 1 , f[j][i + 1] = f[j][i] = 0;
				}
			}
		}
		for(int i = 0 ; i <= 30 ; i++ )
		{
			memset(vis , 0 , sizeof(vis));
			for(int j = 1 ; j <= n ; j++ )
				if(f[i][j] != 2) q.push(j) , vis[j] = 1;
			if(q.empty())
			{
				int a0 = (DAND >> i) & 1;
				f[i][1] = f[i][3] = a0; q.push(1); q.push(3); vis[1] = vis[3] = 1;
			}
			while(!q.empty())
			{
				int u = q.front(); q.pop();
				if(f[i][u] == 0)
				{
					if(u != 1 && !vis[u - 1]) 
					{
						int a0 = (OR[u - 1] >> i) & 1;
						f[i][u - 1] = a0; q.push(u - 1); vis[u - 1] = 1;
					}
					if(u != n && !vis[u + 1]) 
					{
						int a0 = (OR[u] >> i) & 1;
						f[i][u + 1] = a0; q.push(u + 1); vis[u + 1] = 1;
					}
				}
				if(f[i][u] == 1)
				{
					if(u != 1 && !vis[u - 1]) 
					{
						int a0 = (AND[u - 1] >> i) & 1;
						f[i][u - 1] = a0; q.push(u - 1); vis[u - 1] = 1;
					}
					if(u != n && !vis[u + 1]) 
					{
						int a0 = (AND[u] >> i) & 1;
						f[i][u + 1] = a0; q.push(u + 1); vis[u + 1] = 1;
					}
				}
			}
			for(int j = 1 ; j <= n ; j++ ) a[j] += (f[i][j] << i);
		}
		sort(a + 1 , a + n + 1);
		printf("finish %d" , a[m]); fflush(stdout);
	}
	return 0;
}
/*

*/