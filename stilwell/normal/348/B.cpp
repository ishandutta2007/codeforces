#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,u,v;
int son[100005],next[200005],ed[200005],tot;
long long a[100005],b[100005],sum;
bool vis[100005];

long long gcd(long long a,long long b){if(!b)return a;return gcd(b,a%b);}
void dfs(int x)
{
	b[x]=1;vis[x]=true;
	if(vis[ed[son[x]]]&&!next[son[x]])return;
	int son_tot=0;a[x]=sum;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		++son_tot;
		dfs(ed[i]);
		if(b[x]/gcd(b[x],b[ed[i]])>sum/b[ed[i]])
		{
			printf("%I64d\n",sum);
			exit(0);
		}
		b[x]=b[x]/gcd(b[x],b[ed[i]])*b[ed[i]];
		if(a[ed[i]]<a[x])a[x]=a[ed[i]];
	}
	a[x]=a[x]/b[x]*b[x]*son_tot;
	b[x]*=son_tot;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]),sum+=a[i];
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	dfs(1);
	printf("%I64d\n",sum-a[1]);
}