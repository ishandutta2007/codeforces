#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,p,i,j,k,Ans;
long long ans,sum;

long long sqr(long long x){return x*x;}

int main()
{
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("%I64d\n",sqr(n));
		for(i=1;i<=n;++i)printf("o");
		printf("\n");
		return 0;
	}
	if(!n)
	{
		printf("%I64d\n",-sqr(m));
		for(i=1;i<=m;++i)printf("x");
		printf("\n");
		return 0;
	}
	ans=-10000000000ll;
	for(p=min(n,m);p;--p)
	{
		sum=(p-1)+sqr(n-p+1);
		if(p==m)sum-=m;
		else
		{
			k=m/(p+1);
			sum-=sqr(k+1)*(m-(p+1)*k)+sqr(k)*(p+1-m+(p+1)*k);
		}
		if(sum>ans)ans=sum,Ans=p;
	}
	printf("%I64d\n",ans);
	k=m/(Ans+1);
	for(i=1;i<=Ans;++i)
	{
		for(j=1;j<=k;++j)printf("x");
		if(i<=m-(Ans+1)*k)printf("x");
		if(i==1)for(j=n-Ans+1;j;--j)printf("o");
		else printf("o");
	}
	for(j=1;j<=k;++j)printf("x");
	printf("\n");
}