#include <bits/stdc++.h>
using namespace std;
int T , l , r , s[20][220000] , ans;
int main()
{
	for(int b = 0 ; b < 20 ; b++ )
	{
		for(int j = 1 ; j <= 200000 ; j++ )
		{
			s[b][j] = s[b][j - 1] + !((j >> b) & 1);
		}
	}
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &l , &r); ans = 1e9;
		for(int i = 0 ; i < 20 ; i++ ) ans = min(ans , s[i][r] - s[i][l - 1]);
		printf("%d\n" , ans);
	}
	return 0; 
}
/*
*/