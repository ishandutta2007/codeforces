#include <bits/stdc++.h>
using namespace std;
int T , n , a[110] , sum;
int check( int a )
{
	for(int i = 2 ; i * i <= a ; i++ )
	{
		if(a % i == 0) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); sum = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , sum += a[i];
		if(check(sum))
		{
			printf("%d\n" , n);
			for(int i = 1 ; i <= n ; i++ ) printf("%d " , i); printf("\n");
		}
		else
		{
			for(int i = 1 ; i <= n ; i++ )
			{
				if(check(sum - a[i]))
				{
					printf("%d\n" , n - 1);
					for(int j = 1 ; j <= n ; j++ ) 
						if(i != j)printf("%d " , j); 
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}
/*
*/