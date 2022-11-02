#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
long long sum,a[1000001],b[1000001],ans,p,tmp,x;

void Out(long long p)
{
	if(p>sum)p=sum;
	tmp=x;
	ans=1;
	while(p)
	{
		if(p%2)ans=ans*tmp%1000000007;
		tmp=tmp*tmp%1000000007;
		p/=2;
	}
	printf("%I64d\n",ans);
	exit(0);
}

int main()
{
	scanf("%d%I64d",&n,&x);
	for(i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		b[i]=1;
		sum+=a[i];
	}
	for(i=1;i<=n;++i)a[i]=sum-a[i];
	for(i=n-1;i>=1;--i)
	{
		if(a[i]==a[i+1])b[i]+=b[i+1];
		else
		{
			while(a[i]!=a[i+1])
			{
				if(b[i+1]%x)Out(a[i+1]);
				b[i+1]/=x;
				++a[i+1];
			}
			b[i]+=b[i+1];
		}
	}
	while(b[1]%x==0)
	{
		b[1]/=x;
		++a[1];
	}
	Out(a[1]);
}