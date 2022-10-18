#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		while(n && !a[n - 1]) n--;
		if(!n) 
		{
			printf("Yes\n");
			continue;
		}
		int flag = 0;
		for(int i = 0; i < n; i++)
		{
			sum = sum + a[i];
			if(i < n - 1 && sum < 1) flag = 1;
		}
		if(flag || sum != 0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
 }