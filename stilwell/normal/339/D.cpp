#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int ans[1000005];

int main()
{
	scanf("%d%d",&n,&m);n=1<<n;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&ans[n+i-1]);
		for(j=n+i-1>>1,k=1;j;j>>=1,k^=1)
		if(k)ans[j]=ans[j<<1]|ans[j<<1|1];
		else ans[j]=ans[j<<1]^ans[j<<1|1];
	}
	for(;m;--m)
	{
		scanf("%d",&i);
		scanf("%d",&ans[n+i-1]);
		for(j=n+i-1>>1,k=1;j;j>>=1,k^=1)
		if(k)ans[j]=ans[j<<1]|ans[j<<1|1];
		else ans[j]=ans[j<<1]^ans[j<<1|1];
		printf("%d\n",ans[1]);
	}
}