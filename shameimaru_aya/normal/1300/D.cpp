#include<bits/stdc++.h>
using namespace std;
int n , x[110000] , y[110000];
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d" , &x[i] , &y[i]);
	}
	x[n + 1] = x[1] , y[n + 1] = y[1];
	if(n % 2 == 1)
	{
		printf("NO");
		return 0;
	}
	int nn = n / 2;
	for(int i = 1 ; i <= nn ; i++ )
	{
		if(x[i + 1] - x[i] != x[i + nn] - x[i + nn + 1])
		{
			printf("NO");
			return 0;
		}
		if(y[i + 1] - y[i] != y[i + nn] - y[i + nn + 1])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
//2 3 4 5 8 13 13 16 17 20