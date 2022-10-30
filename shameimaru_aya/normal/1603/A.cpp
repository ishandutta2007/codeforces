#include <bits/stdc++.h>
using namespace std;
int T , n , a[110000] , it , num , f;
long long L = 1;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); f = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		L = 2;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(a[i] % L == 0)
			{
				printf("NO\n"); f = 1;
				break;
			}
			L = L / __gcd(L , (long long)i + 2) * (i + 2);
			if(L > 1e9) break;
		}
		if(!f) printf("YES\n");
	}
	return 0;
}