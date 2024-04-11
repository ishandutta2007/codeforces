#include <bits/stdc++.h>
using namespace std;
int T , n , m , k[110000] , x , b[110000] , qwq , ans[110000];
vector< int > a[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); qwq = 0;
		for(int i = 1 ; i <= n ; i++ ) b[i] = 0;
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d" , &k[i]); a[i].clear();
			for(int j = 1 ; j <= k[i] ; j++ ) scanf("%d" , &x) , a[i].push_back(x);
			b[a[i][0]]++; ans[i] = a[i][0];
		}
		for(int i = 1 ; i <= n ; i++ )
			if(b[i] > (m + 1) / 2) qwq = i;
		for(int i = 1 ; i <= m ; i++ )
		{
			if(b[qwq] <= (m + 1) / 2 || !qwq) break;
			if(a[i][0] == qwq)
			{
				if(k[i] > 1) 
				{
					b[a[i][0]]-- , ans[i] = a[i][1];
					if(b[qwq] <= (m + 1) / 2) break;
				}
			}
		}
		if(b[qwq] <= (m + 1) / 2 || !qwq)
		{
			printf("YES\n");
			for(int i = 1 ; i <= m ; i++ ) printf("%d " , ans[i]); printf("\n");
		}
		else printf("NO\n");
		
	}
	return 0;
}
/*
1
4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 1
*/