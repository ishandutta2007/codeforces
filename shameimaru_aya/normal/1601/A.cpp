#include <bits/stdc++.h>
using namespace std;
int T , n , a[220000] , t[50] , qwq;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		memset(t , 0 , sizeof(t));
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%d" , &a[i]);
			for(int j = 0 ; j <= 30 ; j++ ) t[j] += (a[i] >> j) & 1;
		}
		qwq = t[0];
		for(int i = 1 ; i <= 30 ; i++ )
		{
			if(t[i]) qwq = __gcd(qwq , t[i]);
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(qwq % i == 0) printf("%d " , i);
		}
		printf("\n");
	}
	return 0;
}