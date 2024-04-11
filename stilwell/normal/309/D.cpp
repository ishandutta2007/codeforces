#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
long long ans,sum;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=m+1;i+i<=n+1;++i)
	{
		sum=0;k=n-m;
		for(j=m+1;j<=n-m;++j)
		{
			for(;k>m;--k)
			if((2*j-i)*(n+1+k-i)-3*i*(n+1-k-i)<0)
			break;
			if(k==m)break;
			sum+=k-m;
		}
		if(i+i<=n)ans+=sum+sum;
		else ans+=sum;
	}
	printf("%I64d\n",ans*3);
}