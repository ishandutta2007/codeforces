#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a1,a2,a3,a4;
int n,i,j,k;

int main()
{
	scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
	if(!a3&&!a4)
	{
		if(a1&&a2){printf("-1\n");return 0;}
		else
		{
			for(i=1;i<=a1;++i)printf("4");
			for(i=1;i<=a2;++i)printf("7");
		}
		return 0;
	}
	if(a3-a4>1||a4-a3>1){printf("-1");return 0;}
	n=a3+a4+1;
	if(a3>=a4&&((a3!=a4)||(a1!=a3)))
	{
		if(a1<n/2+n%2){printf("-1");return 0;}
		if(a2<n/2){printf("-1");return 0;}
		for(i=1;i<=n;++i)
		if(i%2)
		{
			if(i==1)for(j=1;j<=a1-n/2-n%2;++j)printf("4");
			printf("4");
		}
		else
		{
			if(i+2>n)for(j=1;j<=a2-n/2;++j)printf("7");
			printf("7");
		}
	}
	else
	{
		if(a3>a4){printf("-1");return 0;}
		if(a1<n/2){printf("-1");return 0;}
		if(a2<n/2+n%2){printf("-1");return 0;}
		for(i=1;i<=n;++i)
		if(i%2)
		{
			if(i+2>n)for(j=1;j<=a2-n/2-n%2;++j)printf("7");
			printf("7");
		}
		else
		{
			if(i==2)for(j=1;j<=a1-n/2;++j)printf("4");
			printf("4");
		}
	}
}