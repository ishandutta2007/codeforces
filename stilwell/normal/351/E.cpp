#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,x,y;
int a[2005],ans,s1,s2;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)a[i]=-a[i];
	}
	for(i=1;i<=n;++i)
	{
		s1=s2=0;
		for(j=i+1;j<=n;++j)if(a[i]>a[j])++s1;
		for(j=1;j<i;++j)if(a[i]>a[j])++s2;
		ans+=min(s1,s2);
	}
	printf("%d\n",ans);
}