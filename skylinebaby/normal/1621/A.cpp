#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		int ans = 0;
		scanf("%d %d", &n, &k);
		if(2 * k > n + 1)
		{
			printf("-1\n");
			continue;
		}
		for(int i = 0; i < n; i++) 
		{
			for(int j = 0; j < n; j++)
			{
				if(j == i && !(i & 1) && k)
				{
					printf("R");
					k--;
				}
				else printf(".");
			}			
			printf("\n");
		}
	}
	return 0;
}