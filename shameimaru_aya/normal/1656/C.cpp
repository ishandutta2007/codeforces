#include <bits/stdc++.h>
using namespace std;
int T , n , k , a[220000] , f0 , f1 , f2;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); f0 = f1 = f2 = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			scanf("%d" , &a[i]);
			if(a[i] == 0) f0 = 1;
			if(a[i] == 1) f1 = 1;
			if(a[i] == 2) f2 = 1;
		}
		if((f0 && f1) || (f1 && f2)) printf("NO\n");
		else 
		{
			if(f1)
			{
				int gg = 0;
				sort(a + 1 , a + n + 1);
				for(int i = n ; i >= 2 ; i-- )
				{
					if(a[i - 1] == a[i] - 1)
					{
						gg = 1; printf("NO\n");
						break;
					}
				}
				if(!gg) printf("YES\n");
			}
			else printf("YES\n");
		}
	}
	return 0;
}
/*
*/