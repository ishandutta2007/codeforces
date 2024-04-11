#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int a[233333],ans=233333;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1)
	{
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<ans)
			{
				ans=a[i];
			}
		}
	}
	else if(m==2)
	{
		ans=max(a[1],a[n]);
	}
	else
	{
		ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ans)
			{
				ans=a[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}