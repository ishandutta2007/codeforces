#include <bits/stdc++.h>
using namespace std;
int T , n , m , a[110000] , ans[110000] , las;
string s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		cin >> s;
		for(int i = 1 ; i <= n ; i++ ) a[i] = s[i - 1] - '0' , ans[i] = a[i];
		las = 0;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(a[i]) 
			{
				if(!las)
				{
					for(int j = 0 ; j <= m ; j++ )
					{
						if(i - j <= 0) break;
						ans[i - j] = 1;
					}
					las = i;
					continue;
				}
				int u = m + 1 , il = las , ir = i;
				while(u--)
				{
					ans[il] = ans[ir] = 1; il++; ir--;
					if(il >= ir) break;
				}
				las = i;
			}
		}
		if(las) 
		{
			for(int j = 0 ; j <= m ; j++ )
			{
				if(las + j > n) break;
				ans[las + j] = 1;
			}
		}
		for(int i = 1 ; i <= n ; i++ ) printf("%d" , ans[i]); printf("\n");
	}
	return 0;
}
/*

*/