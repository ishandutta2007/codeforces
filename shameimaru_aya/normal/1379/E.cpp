#include<bits/stdc++.h>
using namespace std;
int n , k , las;
int main()
{
//	freopen("1.in" , "r" , stdin);
	scanf("%d%d" , &n , &k);
	if(n % 2 == 0 || (k > (n - 3) / 2 && n != 1) || (n == 9 && k == 2)
	|| (((int)(pow(2 , (int)log2(n + 1)) + 1e-8)) != n + 1 && k == 0) 
	|| (((int)(pow(2 , (int)log2(n + 1)) + 1e-8)) == n + 1 && k == 1) || n <= 3 && k > 0)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(k > 1)
	{
		printf("0 "); las = 1;
	}
	for(int i = 2 ; i <= 2 * (k - 1) ; i++ )
	{
		printf("%d " , las);
		if(i & 1) las = i;
	}
	if(((int)(pow(2 , (int)log2(n - max(0 , 2 * (k - 1))) + 1) + 1e-8)) != n - max(0 , 2 * (k - 1)) + 1)
	{
		printf("%d " , las); las = max(0 , 2 * (k - 1));
		for(int i = max(2 * k , 2) ; i <= n ; i++ ) printf("%d " , (i - las >> 1) + las);
	}
	else
	{
		if(k)
		{
			printf("%d " , las); las = max(0 , 2 * (k - 1));
			for(int i = max(2 * k , 2) ; i <= n - 2 ; i++ ) printf("%d " , (i - las >> 1) + las);
			if(n >= 2) printf("2 2");
		}
		else 
		{
			printf("%d " , las); las = max(0 , 2 * (k - 1));
			for(int i = max(2 * k , 2) ; i <= n ; i++ ) printf("%d " , (i - las >> 1) + las);
		}
	}
    return 0;
}
/*
*/