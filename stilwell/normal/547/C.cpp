#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x,y,tot;
int a[200005],p[500005],prime[500005],miu[500005],cnt[500005];
long long ans;
bool use[200005];

int main()
{
	n=500000;
	for(i=2;i<=n;++i)
	{
		if(!p[i])prime[++tot]=p[i]=i;
		for(j=1;j<=tot&&prime[j]<=p[i]&&prime[j]<=n/i;++j)p[i*prime[j]]=prime[j];
	}
	miu[1]=1;
	for(i=2;i<=n;++i)
	if(p[i]!=p[i/p[i]])miu[i]=-miu[i/p[i]];
	else miu[i]=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(;m;--m)
	{
		scanf("%d",&x);
		if(use[x])
		{
			use[x]=false;x=a[x];
			for(i=1;i*i<=x;++i)
			if(x%i==0)
			{
				--cnt[i];
				if(i*i!=x)--cnt[x/i];
			}
			for(i=1;i*i<=x;++i)
			if(x%i==0)
			{
				ans-=cnt[i]*miu[i];
				if(i*i!=x)ans-=cnt[x/i]*miu[x/i];
			}
		}
		else
		{
			use[x]=true;x=a[x];
			for(i=1;i*i<=x;++i)
			if(x%i==0)
			{
				ans+=cnt[i]*miu[i];
				if(i*i!=x)ans+=cnt[x/i]*miu[x/i];
			}
			for(i=1;i*i<=x;++i)
			if(x%i==0)
			{
				++cnt[i];
				if(i*i!=x)++cnt[x/i];
			}
		}
		printf("%I64d\n",ans);
	}
}