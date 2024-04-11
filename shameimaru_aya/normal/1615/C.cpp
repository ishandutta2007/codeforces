#include <bits/stdc++.h>
using namespace std;
int T , n , ans , t0 , t1;
char s[110000] , t[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%s%s" , &n , s + 1 , t + 1); ans = 1e9; t0 = t1 = 0;
		for(int i = 1 ; i <= n ; i++ ) t0 += (s[i] == '1' && t[i] == '0');
		for(int i = 1 ; i <= n ; i++ ) t1 += (t[i] == '1' && s[i] == '0');
		if(t0 == t1) ans = t0 * 2;
		for(int i = 1 ; i <= n ; i++ ) s[i] ^= 1; t0 = t1 = 0;
		for(int i = 1 ; i <= n ; i++ ) t0 += (s[i] == '1' && t[i] == '0');
		for(int i = 1 ; i <= n ; i++ ) t1 += (t[i] == '1' && s[i] == '0');
		if(t0 == t1 - 1) ans = min(ans , t0 + t1);
		if(ans > n) printf("-1\n");
		else printf("%d\n" , ans);
	}
	return 0; 
}
/*
*/