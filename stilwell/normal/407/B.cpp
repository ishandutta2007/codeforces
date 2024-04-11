#include <stdio.h>
#include <stdlib.h>
#define P 1000000007
using namespace std;

long long g[1005],ans;
int p[1005],n,i,j,k;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&p[i]);
	for(i=1;i<=n;++i)
	{
		g[i]=1;
		for(j=p[i];j<i;++j)
		g[i]=(g[i]+g[j]+1)%P;
	}
	for(i=1;i<=n;++i)ans=(ans+g[i]+1)%P;
	printf("%I64d\n",ans);
}