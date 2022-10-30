#include <bits/stdc++.h>
using namespace std;
int T , n , k , a[220000] , gg;
map< int , int > mp;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &k); mp.clear(); gg = 1;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , mp[a[i]] = 1;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(mp[a[i] - k] || mp[a[i] + k]) 
			{
				printf("YES\n"); gg = 0;
				break;
			}
		}
		if(gg) printf("NO\n");
	}
	return 0;
}
/*
*/