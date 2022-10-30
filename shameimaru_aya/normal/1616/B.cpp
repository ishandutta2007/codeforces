#include <bits/stdc++.h> 
using namespace std;
int T , n , pl , ans;
char s[110000];
string tt , qwq;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%s" , &n , s); pl = 0; tt.clear(); qwq.clear();
		for(int i = 1 ; i < n ; i++ )
		{
			if(s[i] < s[i - 1]) pl = i;
			if(s[i] > s[i - 1]) break;
		}
		for(int i = pl ; i < n ; i++ )
		{
			if(s[i] != s[pl]) break;
			ans = i;
		}
		for(int i = 0 ; i <= ans ; i++ ) tt += s[i];
		for(int i = 0 ; i <= ans ; i++ ) tt += s[ans - i]; 
		qwq += s[0]; qwq += s[0]; 
		if(tt > qwq) swap(tt , qwq);
		cout << tt << '\n';
	}
    return 0;
} 
/*
*/