#include<bits/stdc++.h>
using namespace std;
int a[300];
int main()
{
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans = n;
	for(int i = 0;i<=n-1;i++)
	{
		if (a[n-1]<=a[i]+d)
		{
			ans = min (ans, i);
			break;
		}
		for(int j = i+1;j<=n-1;j++)
		{
			if (a[j]>a[i]+d) 
			{
				ans = min(ans,i+n-j);
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}