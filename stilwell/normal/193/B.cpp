#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,r,i,j;
int a[105],b[105],p[105],k[105];
long long ans,tmp;

void dfs(int x,bool f)
{
	if((m-x+1)%2==0)
	{
		tmp=0;
		for(int i=1;i<=n;++i)tmp+=a[i]*k[i];
		if(tmp>ans)ans=tmp;
	}
	if(x>m)return;
	
	int A[35];
	for(int i=1;i<=n;++i)A[i]=a[i];
	if(f)
	{
		for(int i=1;i<=n;++i)a[i]=A[i]^b[i];
		dfs(x+1,false);
	}
	for(int i=1;i<=n;++i)a[i]=A[p[i]]+r;
	dfs(x+1,true);
}

int main()
{
	scanf("%d%d%d",&n,&m,&r);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)scanf("%d",&b[i]);
	for(i=1;i<=n;++i)scanf("%d",&k[i]);
	for(i=1;i<=n;++i)scanf("%d",&p[i]);
	ans=0x8000000000000000ll;
	dfs(1,true);
	printf("%I64d\n",ans);
}