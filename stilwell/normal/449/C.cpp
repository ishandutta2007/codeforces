#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,last;
int p[100005],pp[100005],prime[100005],tot;
int son[100005],next[100005],cnt[100005];
bool del[100005];
int u[100005],v[100005],ans;

int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		if(!p[i])prime[++tot]=p[i]=i;
		for(j=1;j<=tot&&prime[j]<=n/i&&prime[j]<=p[i];++j)p[prime[j]*i]=prime[j];
	}
	for(i=2;i<=n;++i)
	{
		for(j=i;p[j]==2;j/=2);
		if(j==1)pp[i]=2;else pp[i]=p[j];
	}
	for(i=2;i<=n;++i)next[i]=son[pp[i]],son[pp[i]]=i,++cnt[pp[i]];
	last=0;
	for(i=2;i<=n;++i)
	if(cnt[i]%2&&i*2<=n)
	{
		if(!last)last=2*i;
		else
		{
			++ans;u[ans]=2*i;v[ans]=last;
			del[2*i]=true;del[last]=true;
			last=0;
		}
	}
	for(i=1;i<=n;++i)
	{
		last=0;
		for(j=son[i];j;j=next[j])
		if(!del[j])
		{
			if(!last)last=j;
			else
			{
				++ans;u[ans]=j;v[ans]=last;
				last=0;
			}
		}
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;++i)printf("%d %d\n",u[i],v[i]);
}