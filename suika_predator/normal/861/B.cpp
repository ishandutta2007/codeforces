#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,flag;
int a[233],b[233];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=1;i<=110;i++)
	{
		int flag2=1;
		for(int j=1;j<=m;j++)
		{
			if((a[j]-1)/i!=b[j]-1)
			{
				flag2=0;
				break;
			}
		}
		if(flag2)
		{
			if(flag&&flag!=(n-1)/i+1)
			{
				flag=-1;
				break;
			}
			flag=(n-1)/i+1;
		}
	}
	printf("%d\n",flag);
	return 0;
}