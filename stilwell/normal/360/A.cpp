#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,opt,l,r,x;
int oo[5005],ll[5005],rr[5005],xx[5005];
int a[5005],lim[5005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)lim[i]=1000000000;
	for(j=1;j<=m;++j)
	{
		scanf("%d%d%d%d",&opt,&l,&r,&x);
		oo[j]=opt;ll[j]=l;rr[j]=r;xx[j]=x;
		if(opt==1)
		{
			for(i=l;i<=r;++i)a[i]+=x;
		}
		else
		{
			for(i=l;i<=r;++i)
			if(x-a[i]<lim[i])lim[i]=x-a[i];
		}
	}
	for(i=1;i<=n;++i)a[i]=lim[i];
	for(j=1;j<=m;++j)
	{
		opt=oo[j];l=ll[j];r=rr[j];x=xx[j];
		if(opt==1)
		{
			for(i=l;i<=r;++i)a[i]+=x;
		}
		else
		{
			k=0x80000000;
			for(i=l;i<=r;++i)
			if(a[i]>k)k=a[i];
			if(k!=x)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(i=1;i<=n;++i)
	{
		printf("%d",lim[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}
}