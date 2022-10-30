#include <bits/stdc++.h> 
using namespace std;
int n , m , a[550][550] , b[550][550] , ans , flag;
string str;
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
	for(int i = 1 ; i < n ; i++ )
	{
		for(int j = 1 ; j < m ; j++ )
		{
			if(b[i][j] && b[n][j] && b[i][m] && b[n][m]) 
			{
				ans--;
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	printf("%d" , ans);
	return 0;
}
/*
*/