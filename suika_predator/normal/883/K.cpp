#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int MAXN=200010,Inf=0x3f3f3f3f;
int n,m;
int a[MAXN],b[MAXN],c[MAXN];
long long tot,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		c[i]=a[i];
		tot+=a[i];
		b[i]+=a[i];
	}
	a[0]=Inf;
	a[n+1]=Inf;
	for(int i=1;i<=n;i++)
	{
		a[i]=min(a[i-1]+1,b[i]);
		if(a[i]<c[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=n;i>=1;i--)
	{
		a[i]=min(a[i+1]+1,min(b[i],a[i]));
		ans+=a[i];
		if(a[i]<c[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%I64d\n",ans-tot);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}