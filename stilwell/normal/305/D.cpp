#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,m,K,i,j,k,u,v,ans;
int sum[1000005],pow2[1000005];

int main()
{
	scanf("%d%d%d",&n,&m,&K);++K;
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		if(u+1==v)continue;
		if(u+K==v){sum[u]=1;continue;}
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;++i)sum[i]+=sum[i-1];
	for(i=K;i<=n;++i)
	if(sum[i]-sum[i-1]&&sum[i-K])
	{
		printf("0\n");
		return 0;
	}
	pow2[0]=1;
	for(i=1;i<=n;++i)
	{
		pow2[i]=pow2[i-1]+pow2[i-1];
		if(pow2[i]>=p)pow2[i]-=p;
	}
	ans=(sum[n]==0);
	for(i=1;i<=n-K;++i)
	if(sum[i]==sum[n]&&(i<=K||sum[i-K]==0))
	{
		ans+=pow2[min(i,K)-sum[i-1]-1];
		if(ans>=p)ans-=p;
	}
	printf("%d\n",ans);
}