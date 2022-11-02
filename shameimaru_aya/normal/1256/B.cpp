#include<bits/stdc++.h> 
using namespace std;
int T , n , a[110] , f[110] , num[110] , pl[110];
int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
			pl[a[i]] = i;
		}
		memset(f , 0 , sizeof(f));
		memset(num , 0 , sizeof(num));
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <= n ; j++ )
			{
				if(num[j]) continue;
				int flag = 0;
				for(int k = i ; k < pl[j] ; k++ )
				{
					flag += f[k];
				}
				if(!flag)
				{
					for(int k = i ; k < pl[j] ; k++ )
					{
						f[k] = 1;
					}
					for(int k = 1 ; k <= n ; k++ )
					{
						if(!num[a[k]] && pl[a[k]] < pl[j]) pl[a[k]]++;
					}
					num[j] = 1;
					printf("%d " , j);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}