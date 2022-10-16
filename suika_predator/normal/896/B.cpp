#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,c;
int a[2333];
int p;
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int o=1;o<=m;o++)
	{
		scanf("%d",&p);
		if(p<=c/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0||a[i]>p)
				{
					printf("%d\n",i);
					a[i]=p;
					break;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[i]==0||a[i]<p)
				{
					printf("%d\n",i);
					a[i]=p;
					break;
				}
			}
		}
		fflush(stdout);
		int cur=1,flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<cur)
			{
				flag=0;
				break;
			}
		}
		if(flag)break;
	}
	return 0;
}