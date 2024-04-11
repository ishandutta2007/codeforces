#include<bits/stdc++.h>
using namespace std;
int a[312345];
int b[312345];
int n,m;
int solve(int x)
{
	int need = 0;
	if(a[0]>=m-x) need = 0;
	else need = a[0];
	for(int i = 1;i<n;i++)
	{
		if(a[i]<=need) 
		{
			if(need-a[i]>x) return 0;	
		}
		else 
		{
			if (a[i]+x<need+m) need = a[i];
		} 
	}
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(solve(0)) 
	{
		printf("0\n");
		return 0;
	}
	int d = 19;
	int ans = 0;
	while(d--)
	{
		if(ans+(1<<d)<m && !solve(ans+(1<<d))) ans += 1<<d;
	}
	printf("%d\n",ans+1);
	return 0;
}