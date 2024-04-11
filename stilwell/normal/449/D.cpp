#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int N,n,i,j,k;
int a[2000005],b[2000005],c[2000005];
long long Power[2000005],ans,tmp;

int main()
{
	N=1048575;
	scanf("%d",&n);	
	Power[0]=1;
	for(i=1;i<=n;++i)Power[i]=Power[i-1]*2%p;
	for(i=1;i<=n;++i)scanf("%d",&a[i]),++b[a[i]];
	for(i=0;i<20;++i)
	for(j=0;j<=N;++j)
	if(j&(1<<i))b[j-(1<<i)]+=b[j],++c[j];
	for(i=0;i<=N;++i)
	{
		tmp=(Power[b[i]]+p-1)%p;
		if(c[i]%2)ans=(ans+p-tmp)%p;
		else ans=(ans+tmp)%p;
	}
	printf("%I64d\n",ans);
}