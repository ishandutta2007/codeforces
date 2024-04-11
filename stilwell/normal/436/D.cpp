#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,Max,lim;
int a[100005],b[100005],l[100005],r[100005];
int f[100005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	a[0]=a[1]-1000;a[n+1]=a[n]+1000;
	for(i=1;i<=n;++i)if(a[i]==a[i-1]+1)l[i]=l[i-1];else l[i]=i;
	for(i=n;i>=1;--i)if(a[i]==a[i+1]-1)r[i]=r[i+1];else r[i]=i;
	lim=0;
	for(i=1;i<=n;++i)
	{
		while(lim<m&&b[lim+1]<=a[i])++lim;
		if(l[i]==i)Max=f[i-1]+(a[i]==b[lim]);
		else Max=-10000000;
		if(Max>f[i])f[i]=Max;
		for(j=lim;j>=1;--j)
		{
			k=i-(a[i]-b[j]);
			if(k<=0)break;
			k=l[k];
			if(f[k-1]+lim-j+1>f[i])f[i]=f[k-1]+lim-j+1;
			if(f[k-1]+lim-j+1>Max)Max=f[k-1]+lim-j+1;
		}
		for(j=lim+(b[lim]<a[i]);j<=m;++j)
		{
			k=i+(b[j]-a[i]);
			if(k>n)break;
			k=r[k];
			if(Max+j-lim>f[k])f[k]=Max+j-lim;
		}
		if(f[i]>f[i+1])f[i+1]=f[i];
	}
	printf("%d\n",f[n]);
}