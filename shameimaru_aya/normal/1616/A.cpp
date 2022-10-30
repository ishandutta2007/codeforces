#include <bits/stdc++.h> 
using namespace std;
int T , n , a , f[220] , tot;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		memset(f , 0 , sizeof(f)); f[0] = 1;
		tot = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%d" , &a); a = abs(a);
			if(f[a] < 2) tot++; f[a]++;
		}
		printf("%d\n" , tot);
	}
    return 0;
} 
/*
*/