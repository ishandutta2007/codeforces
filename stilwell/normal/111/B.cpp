#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans;
int x[100005],y[100005],last[100005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;++i)
	{
		ans=0;
		for(j=1;j*j<=x[i];++j)
		if(x[i]%j==0)
		{
			if(i-last[j]>y[i])++ans;
			if(j!=x[i]/j&&i-last[x[i]/j]>y[i])++ans;
		}
		printf("%d\n",ans);
		for(j=1;j*j<=x[i];++j)
		if(x[i]%j==0)
		last[j]=i,last[x[i]/j]=i;
	}
}