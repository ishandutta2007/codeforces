#include<bits/stdc++.h>
using namespace std;
int T , n , n2 , a , f[110];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); n2 = n + n;
		memset(f , 0 , sizeof(f));
		for(int i = 1 ; i <= n2 ; i++ )
		{
			scanf("%d" , &a);
			if(!f[a])
			{
				printf("%d " , a);
				f[a] = 1;
			}
		}
		printf("\n");
	}
	
    return 0;
}