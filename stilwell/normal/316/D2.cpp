#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,n1,n2,x,i,j,k;
long long f[1000005],ans;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x==1)++n1;else ++n2;
	}
	f[0]=f[1]=1;
	for(i=2;i<=n1;++i)f[i]=(f[i-1]+(i-1)*f[i-2])%p;
	ans=f[n1];
	for(i=1;i<=n2;++i)ans=ans*(n1+i)%p;
	printf("%I64d\n",ans);
}