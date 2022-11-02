#include <stdio.h>
#include <stdlib.h>
using namespace std;

int fa[300005],son[300005],next[300005],deep[300005];
int st[300005],en[300005],tot;
int n,m,i,j,k,opt,u,x,y,z;
long long sum1[600005],sum2[600005],ans;

void dfs(int x)
{
	st[x]=++tot;
	for(int i=son[x];i;i=next[i])
	{
		deep[i]=deep[x]+1;
		dfs(i);
	}
	en[x]=++tot;
}

void M(long long *A,int x,long long y){for(;x<=tot;x+=x&-x)A[x]=(A[x]+y)%1000000007;}
void Q(long long *A,int x,int y){for(;x;x-=x&-x)ans=(ans+A[x]*y)%1000000007;}

int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&fa[i]);
		next[i]=son[fa[i]];
		son[fa[i]]=i;
	}
	dfs(1);
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			M(sum1,st[x],y);
			M(sum1,en[x],-y);
			M(sum2,st[x],-z);
			M(sum2,en[x],z);
			M(sum1,st[x],(long long)deep[x]*z);
			M(sum1,en[x],-(long long)deep[x]*z);
		}
		else
		{
			scanf("%d",&u);
			ans=0;
			Q(sum1,st[u],1);
			Q(sum2,st[u],deep[u]);
			printf("%I64d\n",(ans+1000000007)%1000000007);
		}
	}
}