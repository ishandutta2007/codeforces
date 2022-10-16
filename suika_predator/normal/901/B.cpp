#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[233],b[233],c[233];
int main()
{
	scanf("%d",&n);
	b[1]=1;
	c[0]=1;
	for(int t=2;t<=n;t++)
	{
		a[0]=0;
		for(int i=1;i<=t;i++)
		{
			a[i]=b[i-1];
		}
		for(int i=0;i<=t-1;i++)
		{
			a[i]+=c[i];
			a[i]%=2;
		}
		for(int i=0;i<=t;i++)c[i]=b[i];
		for(int i=0;i<=t;i++)b[i]=a[i];
	}
	if(b[n]==-1)for(int i=0;i<=n;i++)b[i]*=-1;
	if(c[n-1]==-1)for(int i=0;i<=n-1;i++)c[i]*=-1;
	printf("%d\n",n);
	for(int i=0;i<=n;i++)printf("%d ",b[i]);printf("\n");
	printf("%d\n",n-1);
	for(int i=0;i<=n-1;i++)printf("%d ",c[i]);printf("\n");
	return 0;
}