#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
long long K,l,r,mid,sum,ans,tmp;

int main()
{
	scanf("%d%d%I64d",&n,&m,&K);
	l=1;r=(long long)n*m;ans=1;
	while(l<=r)
	{
		mid=(l+r)/2;sum=0;
		for(i=1;i<=n;++i)
		{
			tmp=mid/i;
			if(m<tmp)tmp=m;
			sum+=tmp;
		}
		if(sum>=K)ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
}