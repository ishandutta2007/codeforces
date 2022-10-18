#include<bits/stdc++.h>
using namespace std;
int a[212345];
int b[212345];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	for(int i = 0;i<n;i++) scanf("%d",&b[i]);
	int pos = n;
	for(int i = 0;i<n;i++) 
	{
		if(b[i]==1) pos = i;
	}
	int ans = -2;
	if(pos<n)
	{
		int flag = 0;
		for(int i = pos+1;i<n;i++)
		{
			if(b[i]!=b[i-1] + 1) flag = 1;
		}
		for(int i = 0;i<pos;i++)
		{
			if(b[i]&&b[i]<=i+n-pos+1) flag = 1;
		}
		if(!flag)
		{
			printf("%d\n",pos);
			return 0;
		}
		else 
		{
			for(int i = pos;i<n;i++) if(b[i])
			{
				ans = max(ans,i-b[i]);
			}
			ans += n+2; 
		}
	}
	else 
	{
		for(int i = 0;i<n;i++) if(b[i]) 
		{
			ans = max(ans,i-b[i]);
		}
		ans += n+2; 		
	}
	printf("%d\n",ans);
}