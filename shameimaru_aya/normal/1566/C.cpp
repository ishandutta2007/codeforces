#include <bits/stdc++.h>
using namespace std;
int T , n , ans , val[2][2];
char s[110000] , t[110000];
int main()
{
	val[0][0] = 1; val[1][1] = 0; val[0][1] = val[1][0] = 2;
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); scanf("%s" , s + 1); scanf("%s" , t + 1); ans = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(s[i] == t[i])
			{
				if(i < n)
				{
					if(s[i + 1] == t[i + 1] && s[i + 1] != s[i]) 
					{
						ans += 2;
						i++;
					}
					else ans += val[s[i] - '0'][t[i] - '0'];
				}
				else ans += val[s[i] - '0'][t[i] - '0'];
			}
			else ans += 2;
		}
		printf("%d\n" , ans);
	}
	return 0;  
}
/*
1
2
00
11
*/