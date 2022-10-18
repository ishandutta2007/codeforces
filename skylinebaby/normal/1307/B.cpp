#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		int mx = 0;
		int flag = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			mx = max(mx, a[i]);
			if(a[i] == x) flag = 1;
		}
		if(mx <= x)
		{
			printf("%d\n", (mx + x - 1) / mx);
		} 
		else if(flag)
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
	return 0;
}