#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,opt,l,r,ans;
int a[300005],b[300005],c[300005],sum[300005];

void suit(int x)
{
	if(!x)return;
	for(i=x;i<=n;i+=i&-i)sum[i]-=b[x];
	if(a[x]>a[x+1])b[x]=1;else b[x]=0;
	for(i=x;i<=n;i+=i&-i)sum[i]+=b[x];
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		a[c[i]]=i;
	}
	for(i=1;i<n;++i)if(a[i]>a[i+1])b[i]=1;
	for(i=1;i<=n;++i)
	for(j=i;j<=n;j+=j&-j)
	sum[j]+=b[i];
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			ans=0;
			for(i=r-1;i;i-=i&-i)ans+=sum[i];
			for(i=l-1;i;i-=i&-i)ans-=sum[i];
			printf("%d\n",ans+1);
		}
		else
		{
			swap(c[l],c[r]);
			l=c[l];r=c[r];
			swap(a[l],a[r]);
			suit(l-1);
			suit(l);
			suit(r-1);
			suit(r);
		}
	}
}