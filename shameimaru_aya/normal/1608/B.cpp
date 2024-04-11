#include <bits/stdc++.h> 
using namespace std;
int T , n , a , b , l , r;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &n , &a , &b);
		if(abs(a - b) >= 2 || a > (n - 1) / 2 || b > (n - 1) / 2 || a + b > n - 2) 
		{
			printf("-1\n");
			continue;
		}
		if(a < b)
		{
			for(int i = 1 ; i <= b ; i++ ) printf("%d %d " , n + 1 - i , i);
			for(int i = b + 1 ; i <= n - b ; i++ ) printf("%d " , i);
			printf("\n");
		}
		if(a == b)
		{
			for(int i = 1 ; i <= b ; i++ ) printf("%d %d " , n + 1 - i , i);
			for(int i = n - b ; i >= b + 1 ; i-- ) printf("%d " , i);
			printf("\n");
		}
		if(a > b)
		{
			for(int i = 1 ; i <= a ; i++ ) printf("%d %d " , i , n + 1 - i);
			for(int i = n - a ; i >= a + 1 ; i-- ) printf("%d " , i);
			printf("\n");
		}
	}
    return 0;
}
/*

*/