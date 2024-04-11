#include <bits/stdc++.h>
using namespace std;
int T , n , m , s1[500] , s2[500] , s[500] , ans , minn;
char mp[500][500];
int main() 
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); ans = 1e9;
		for(int i = 1 ; i <= n ; i++ ) scanf("%s" , &mp[i][1]);
		for(int i = 1 ; i <= n ; i++ ) 
			for(int j = 1 ; j <= m ; j++ ) mp[i][j] -= '0';
		for(int l = 1 ; l <= n ; l++ )
		{
			memset(s1 , 0 , sizeof(s1));
			memset(s2 , 0 , sizeof(s2));
			memset(s , 0 , sizeof(s));
			for(int j = 1 ; j <= m ; j++ ) s1[j] = s1[j - 1] + (!mp[l][j]);
			for(int i = l + 1 ; i < l + 4 ; i++ )
				for(int j = 1 ; j <= m ; j++ ) s[j] += mp[i][j];
			for(int j = 1 ; j <= m ; j++ ) s[j] += s[j - 1];
			for(int r = l + 4 ; r <= n ; r++ )
			{
				for(int j = 1 ; j <= m ; j++ ) s2[j] = s2[j - 1] + (!mp[r][j]);
				int minn = 1e9;
				for(int j = 1 ; j <= m ; j++ )
				{
					if(j - 3 <= 0) continue;
					minn = min(minn , -s1[j - 3] - s2[j - 3] - s[j - 3] - (s[j - 3] - s[j - 4]));
					ans = min(ans , minn + s1[j - 1] + s2[j - 1] + s[j - 1] + 2 * (r - l - 1) - (s[j] - s[j - 1]));
				}
				int qwq = 0;
				for(int j = 1 ; j <= m ; j++ ) 
				{
					qwq += mp[r][j]; s[j] += qwq;
				}
			}
		}
		printf("%d\n" ,  ans);
	}
	return 0;
}
/*

*/