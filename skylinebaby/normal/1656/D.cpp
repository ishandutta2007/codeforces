#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
			long long x;
			scanf("%lld", &x);
			if(x == 1)
			{
				printf("-1\n");
				continue;
			}
			if(x % 2 == 1)
			{
				printf("2\n");
				continue;
			}
			long long z = 1;
			while(x % 2 == 0)
			{
				z = z * 2;
				x = x / 2;
			}
			if(x == 1)
			{
				printf("-1\n");
				continue;
			}
			if(z * 2 > x)
			{
				printf("%lld\n", x);
				continue;
			}
			printf("%lld\n", z * 2);
			
	}
	return 0;
}