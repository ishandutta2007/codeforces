#include<bits/stdc++.h>
using namespace std;
int T , n , a[110000] , x[35] , y[35] , flag;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		memset(x , 0 , sizeof(x)); memset(y , 0 , sizeof(y)); 
		flag = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
			for(int j = 0 ; j <= 30 ; j++ )
			{
				if(a[i] >> j & 1) x[j]++;
				else y[j]++;
			}
		}
		for(int i = 30 ; i >= 0 ; i-- )
		{
			if(!(x[i] & 1)) continue;
			if(x[i] % 4 == 3 && y[i] % 2 == 0) printf("LOSE\n");
			else printf("WIN\n");
			flag = 1;
			break;
		}
		if(!flag) printf("DRAW\n");
	}
	return 0;
}