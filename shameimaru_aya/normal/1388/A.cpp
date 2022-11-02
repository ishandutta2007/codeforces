#include<bits/stdc++.h>
using namespace std;
int T , n , a = 6 , b = 10 , c = 14;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		if(n > a + b + c)
		{
			if(n - a - b - c == 6 || n - a - b - c == 10 || n - a - b - c == 14)
			printf("YES\n%d %d %d %d\n" , a , b , c + 1 , n - a - b - c - 1);
			else
			printf("YES\n%d %d %d %d\n" , a , b , c , n - a - b - c);
		}
		
		else printf("NO\n");
	}
	return 0;
}