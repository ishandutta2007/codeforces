#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long a[200001],b[200001];
long long l,r,mid,ans;
int n,m,i,j,k;

int tb;
long long dist(int x,int y)
{
	if(a[x]>b[y])return a[x]-b[y];
	else return b[y]-a[x];
}
long long min(long long a,long long b){if(a<b)return a;else return b;}

bool work(long long t)
{
	tb=1;
	for(i=1;i<=n;++i)
	{
		if(dist(i,tb)>t)continue;
		if(b[tb]<a[i])
		{
			j=tb;
			while(tb<=m&&b[tb]<=a[i])++tb;
			while(tb<=m&&(b[tb]-b[j]+min(dist(i,tb),dist(i,j))<=t))++tb;
		}
		else
		{
			while(tb<=m&&b[tb]-a[i]<=t)++tb;
		}
		if(tb>m)return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(i=1;i<=m;++i)scanf("%I64d",&b[i]);
	l=0;r=100000000000LL;
	ans=r;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(work(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
}