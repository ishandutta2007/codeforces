#include<bits/stdc++.h>
using namespace std;
int a[111111];
int ans [111111];
int has [111111];
int main()
{
	int n;
	scanf("%d",&n);
	if (n==1)
	{
		scanf("%d",&n);
		printf("1\n");return 0;
	}
	int max1 = 0;
	int max2 = 0;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>max1) max2=max1,max1=a[i],has[max1]++;
		else if (a[i]>max2) max2=a[i],ans[max1]++; 	
	}
	int mx = 0;
	int ww = 0;
	for(int i = 1;i<=n;i++)
	{
		if (ans[i]>mx) mx = ans[i], ww = i; 
	}
	if (mx>1) printf("%d\n",ww);
	else if (mx==1) 
	{
		for(int i = 1;i<=n;i++)
		{
			if (has[i]==0) {printf("%d\n",i);return 0;} 
		}	
	}
	else
	{
		int tot = 0;
		int ret = n+1;
		for(int i = 0;i<n;i++)
		{
			if (a[i]>tot) tot = a[i];
			else ret = min(ret,a[i]);
		}
		if (ret == n+1) printf("1\n");
		else printf("%d\n",ret);
	} 
	return 0;
}