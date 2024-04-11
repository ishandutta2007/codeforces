#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,r,mid,ans;
int a[2005],f[2005];
int dist[2005][2005];

int Abs(int x){if(x<0)return -x;return x;}

bool check(int mid)
{
	for(i=1;i<=n;++i)f[i]=i-1;
	for(i=1;i<=n;++i)
	{
		if(f[i]+(n-i)<=m)return true;
		for(j=i+1;j<=n;++j)
		{
			if(dist[i][j]<=mid&&f[i]+(j-i-1)<f[j])
			{
				f[j]=f[i]+(j-i-1);
				if(f[j]+(n-j)<=m)return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	dist[i][j]=Abs(a[i]-a[j])/(j-i)+(Abs(a[i]-a[j])%(j-i)!=0);
	for(i=2;i<=n;++i)if(Abs(a[i]-a[i-1])>ans)ans=Abs(a[i]-a[i-1]);
	l=0;r=ans-1;
	while(l<=r)
	{
		mid=((long long)l+r)/2;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}