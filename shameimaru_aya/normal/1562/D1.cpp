#include <bits/stdc++.h>
using namespace std;
int T , n , m , x , y , sum[330000] , b[330000];
string s;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); cin >> s;
		for(int i = 0 ; i < n ; i++ )
			sum[i + 1] = sum[i] + ((s[i] == '-') ^ (i & 1) ? -1 : 1); 
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d" , &x , &y);
			if(sum[y] - sum[x - 1] == 0) printf("0\n");
			else
			{
				if(y - x + 1 & 1) printf("1\n");
				else printf("2\n");
			}
		}
	}
	
	return 0;
}
/*

*/