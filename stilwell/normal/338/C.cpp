#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,c[15],fa[15],Ans;
long long a[15],b[15];

int calc(long long x)
{
	int ans=0;
	long long i;
	for(i=2;i*i<=x;++i)
	if(x%i==0)while(x%i==0)++ans,x/=i;
	if(x>1)++ans;
	return ans;
}

void dfs(int x)
{
	if(x>n)
	{
		int ans=0,k=0;
		for(int i=1;i<=n;++i)if(c[i]>1)++ans;
		for(int i=1;i<=n;++i)
		if(!fa[i])++k,ans+=c[i];
		ans+=(k>1);
		if(ans<Ans)Ans=ans;
		return;
	}
	for(int i=1;i<=n;++i)
	if(i!=x&&b[i]%a[x]==0)
	{
		b[i]/=a[x];
		fa[x]=i;
		dfs(x+1);
		fa[x]=0;
		b[i]*=a[x];
	}
	dfs(x+1);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]),b[i]=a[i],c[i]=calc(a[i]);
	Ans=10000000;
	dfs(1);
	printf("%d\n",Ans);
}