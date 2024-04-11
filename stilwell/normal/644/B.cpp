#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,r;
int t[200005],d[200005],q[200005];
long long pre,ans[200005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d%d",&t[i],&d[i]);
	l=1;r=0;
	for(i=1;i<=n;++i)
	{
		ans[i]=-1;
		if(l>r)q[r=l]=i,pre=t[i];
		else
		{
			for(;l<=r&&pre+d[q[l]]<=t[i];++l)pre+=d[q[l]],ans[q[l]]=pre;
			if(l>r)q[r=l]=i,pre=t[i];
			else if(r-l+1<=m)q[++r]=i;
		}
	}
	for(;l<=r;++l)pre+=d[q[l]],ans[q[l]]=pre;
	for(i=1;i<=n;++i)printf("%lld ",ans[i]);
	printf("\n");
}