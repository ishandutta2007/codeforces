#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int y = -1000000000;
		int z = 0;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			z = max(z, y - x);
			y = max(x, y); 
		}
		int ans = 0;
		while(z)
		{
			z /= 2;
			ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;	
}