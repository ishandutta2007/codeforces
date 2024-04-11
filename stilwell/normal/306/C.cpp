#include <stdio.h>
#include <stdlib.h>
#define p 1000000009
using namespace std;

int n,n1,n2,i,j,k,c1,c2;
long long C[4005][4005],ans;

int main()
{
	scanf("%d%d%d",&n,&n1,&n2);
	C[0][0]=1;
	for(i=0;i<=4000;++i)
	for(j=0;j<=i;++j)
	{
		if(C[i][j]>=p)C[i][j]-=p;
		C[i+1][j]+=C[i][j];
		C[i+1][j+1]+=C[i][j];
	}
	for(i=1;i<=n;++i)
	for(j=i+1;j<n;++j)
	{
		c1=i+n-j;c2=j-i;
		if(c1>n1)continue;
		if(c2>n2)continue;
		ans=(ans+C[n1-1][c1-1]*C[n2-1][c2-1])%p;
	}
	for(i=1;i<=n1;++i)ans=ans*i%p;
	for(i=1;i<=n2;++i)ans=ans*i%p;
	printf("%I64d\n",ans);
}