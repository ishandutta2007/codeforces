#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,l,r;
double p[105],ans,tmp,sum;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lf",&p[i]);
	sort(p+1,p+n+1);
	if(p[n]==1)
	{
		printf("1\n");
		return 0;
	}
	for(l=1;l<=n;++l)
	for(r=l;r<=n;++r)
	{
		tmp=0;sum=1;
		for(i=l;i<=r;++i)sum*=1-p[i];
		for(i=l;i<=r;++i)tmp+=sum/(1-p[i])*p[i];
		if(tmp>ans)ans=tmp;
	}
	printf("%.20lf\n",ans);
}