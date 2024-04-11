#include<bits/stdc++.h>
using namespace std;
int T , n , a[220000] , x , ans;
map< long long , int > mp;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		mp.clear(); ans = 0;
		scanf("%d%d" , &n , &x);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , mp[a[i]]++;
		sort(a + 1 , a + n + 1);
		for(int i = 1 ; i <= n ; i++ )
		{
			if(!mp[a[i]]) continue;
			if(mp[1ll * a[i] * x]) 
			{
				mp[1ll * a[i] * x]--; mp[a[i]]--;
			}
			else ans++ , mp[a[i]]--;
		}
		printf("%d\n" , ans);
	}
	return 0;
}
/*

*/