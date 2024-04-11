#include<bits/stdc++.h>
using namespace std;
int T , ans , pl[10][210000] , tot[10];
string s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		cin >> s;
		ans = 0;
		memset(tot , 0 , sizeof(tot));
		for(int i = 0 ; i < s.size() ; i++ ) pl[s[i] - '0'][++tot[s[i] - '0']] = i;
		for(int i = 0 ; i <= 9 ; i++ )
		{
			for(int j = 0 ; j <= 9 ; j++ )
			{
				if(i == j) continue;
				int a = 1 , b = 1 , t = 0 , noww = -1;
				while(a <= tot[i] && b <= tot[j])
				{
					while(pl[i][a] < noww && a <= tot[i]) a++;
					if(a <= tot[i]) noww = pl[i][a] , a++;
					else break;
					while(pl[j][b] < noww && b <= tot[j]) b++;
					if(b <= tot[j]) noww = pl[j][b] , b++;
					else break;
					t += 2;
				}
				ans = max(ans , t);
			}
		}
		for(int i = 0 ; i <= 9 ; i++ )
		{
			ans = max(ans , tot[i]);
		}
		printf("%d\n" , s.size() - ans);
	}
	return 0;
}