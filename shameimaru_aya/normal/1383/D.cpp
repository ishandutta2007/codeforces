#include<bits/stdc++.h>
using namespace std;
int n , m , a[300][300] , c[300] , r[300] , f[90000] , tot , x[90000] , y[90000] , mp[300][300] , R , C;
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
		for(int j = 1 ; j <= m ; j++ )
			scanf("%d" , &a[i][j]) , r[i] = max(r[i] , a[i][j]) , c[j] = max(c[j] , a[i][j]);
	for(int i = 1 ; i <= n ; i++ ) f[r[i]] ^= 1;
	for(int i = 1 ; i <= m ; i++ ) f[c[i]] ^= 2;
	for(int i = n * m ; i >= 1 ; i-- )
	{
		if(f[i] & 1) R++;
		if(f[i] & 2) C++;
		if(f[i]) mp[R][C] = i;
		if(f[i] & 1)
		{
			for(int j = C - 1 ; j >= 1 ; j-- )
			{
				if(mp[R][j]) break;
				x[++tot] = R , y[tot] = j;
			}
		}
		if(f[i] & 2)
		{
			for(int j = R - 1 ; j >= 1 ; j-- )
			{
				if(mp[j][C]) break;
				x[++tot] = j , y[tot] = C;
			}
		} 
	}
	tot = 0;
	for(int i = n * m ; i >= 1 ; i-- )
	{
		if(f[i]) continue;
		tot++;
		mp[x[tot]][y[tot]] = i;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ ) printf("%d " , mp[i][j]);
		printf("\n");
	}
    return 0;
}
/*
*/