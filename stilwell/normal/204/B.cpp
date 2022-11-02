#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

map <int,int> Hash;

int n,m,a,b,i,j,k,ans;
int A[200005],B[200005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		if(!Hash[a])Hash[a]=++m;
		++A[Hash[a]];
		scanf("%d",&b);
		if(!Hash[b])Hash[b]=++m;
		if(a!=b)++B[Hash[b]];
	}
	ans=1000000;
	for(i=1;i<=m;++i)
	if(A[i]+B[i]>=n/2+n%2)
	{
		if(A[i]>=n/2+n%2)ans=0;
		else if(n/2+n%2-A[i]<ans)
		ans=n/2+n%2-A[i];
	}
	if(ans>n)printf("-1");else printf("%d\n",ans);
}