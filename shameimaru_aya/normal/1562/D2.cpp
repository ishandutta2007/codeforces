#include <bits/stdc++.h>
using namespace std;
int T , n , m , x , y , sum[330000] , b[330000];
string s;
vector< int > id[660000];
int Sum( int l , int r )
{
	return sum[r] - sum[l - 1];
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); cin >> s;
		for(int i = -n ; i <= n ; i++ ) id[i + 330000].clear();
		for(int i = 0 ; i < n ; i++ )
			sum[i + 1] = sum[i] + ((s[i] == '-') ^ (i & 1) ? -1 : 1);
		for(int i = 1 ; i <= n ; i++ ) 
			b[i] = Sum(1 , i - 1) - Sum(i + 1 , n) , id[b[i] + 330000].push_back(i);
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d" , &x , &y);
			if(sum[y] - sum[x - 1] == 0) printf("0\n");
			else
			{
				if(y - x + 1 & 1) 
				{
					printf("1\n");
					int val = Sum(1 , x - 1) - Sum(y + 1 , n) + 330000;
					int qwq = *lower_bound(id[val].begin() , id[val].end() , x);
					printf("%d\n" , qwq);
				}
				else 
				{
					printf("2\n");
					int val = Sum(1 , x - 1) - Sum(y , n) + 330000;
					int qwq = *lower_bound(id[val].begin() , id[val].end() , x);
					printf("%d %d\n" , qwq , y);
				}
			}
		}
	}
	
	return 0;
}
/*

*/