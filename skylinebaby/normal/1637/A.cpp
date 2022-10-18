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
		int flag = 0;
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
		{
			if(i && a[i] < a[i - 1])
			{
				flag = 1;
			}
		}
		if(flag) 
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
 }