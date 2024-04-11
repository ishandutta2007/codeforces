#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[1005];
bool use[1005];
int n,ans,i,j,k,tot;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	tot=0;
	while(tot<n)
	{
		++ans;k=0;
		for(i=1;i<=n;++i)
		if(!use[i]&&a[i]>=k)
		{
			++k;
			use[i]=true;++tot;
		}
	}
	printf("%d\n",ans);
}