#include <bits/stdc++.h>
using namespace std;
int T , n , l[110000] , tot , ok;
string s[110000] , r[110000] , c;
char str[5];
map< string , int > s2 , mp;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		ok = 0; mp.clear(); s2.clear();
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%s" , str); s[i] = r[i] = str;
			l[i] = s[i].size(); reverse(r[i].begin() , r[i].end());
			if(l[i] == 1) ok = 1;
			if(l[i] == 2 && s[i][0] == s[i][1]) ok = 1;
			if(l[i] == 3 && s[i][0] == s[i][2]) ok = 1;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(!mp[s[i]]) mp[s[i]] = i;
			c.clear();
			if(l[i] >= 1) c += s[i][0];
			if(l[i] >= 2)
			{
				c += s[i][1];
				if(!s2[c]) s2[c] = i;
			}
		}
		for(int i = n ; i >= 1 ; i-- )
			if(mp[r[i]] && mp[r[i]] < i) ok = 1;
		for(int i = n ; i >= 1 ; i-- )
		{
			c.clear();
			if(l[i] == 3)
			{
				c += s[i][2]; c += s[i][1]; 
				if(mp[c] && mp[c] < i) ok = 1;
			}
			if(l[i] == 2)
			{
				if(s2[r[i]] && s2[r[i]] < i) ok = 1;
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
*/