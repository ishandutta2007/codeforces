#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,i,j,k,u,v,c;
int son[100005],next[200005],ed[200005],cost[200005],tot;
int size[100005],Max[100005],root;
int belong[100005],d[100005];
int fa[100005],nex[100005],head[100005];
int Min[400005],Min_[400005],l;
int a[100005],cnt;
long long ans;

vector<int> vec[100005];

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}

void dfs(int x)
{
	size[x]=1;
	for(int i=son[x];i;i=next[i])
	if(!size[ed[i]])
	{
		dfs(ed[i]);
		size[x]+=size[ed[i]];
		if(size[ed[i]]>=Max[x])Max[x]=size[ed[i]];
	}
	if(n-size[x]>Max[x])Max[x]=n-size[x];
	if(!root||Max[x]<Max[root])root=x;
}

void dfs2(int x,long long y)
{
	size[x]=1;ans+=y;
	for(int i=son[x];i;i=next[i])
	if(!size[ed[i]])
	{
		dfs2(ed[i],y+cost[i]);
		size[x]+=size[ed[i]];
	}
}

void dfs3(int x)
{
	belong[x]=tot;a[++cnt]=x;
	for(int i=son[x];i;i=next[i])
	if(size[ed[i]]<size[x])dfs3(ed[i]);
}

void update(int x)
{
	if(Min[x<<1])Min[x]=Min[x<<1];
	else Min[x]=Min[x<<1|1];
	if(Min[x<<1]&&belong[Min[x<<1]]!=belong[Min[x]])Min_[x]=Min[x<<1];else 
	if(Min_[x<<1]&&belong[Min_[x<<1]]!=belong[Min[x]])Min_[x]=Min_[x<<1];else 
	if(Min[x<<1|1]&&belong[Min[x<<1|1]]!=belong[Min[x]])Min_[x]=Min[x<<1|1];else
	Min_[x]=Min_[x<<1|1]; 
}

int main()
{
	scanf("%d",&n);
	for(l=1;l<n;l*=2);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&c);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;cost[tot]=c;
	}
	dfs(1);
	for(i=1;i<=n;++i)size[i]=0;
	dfs2(root,0);tot=0;
	printf("%I64d\n",ans*2);
	for(i=son[root];i;i=next[i])
	{
		++tot;cnt=0;
		dfs3(ed[i]);
		sort(a+1,a+cnt+1);
		for(j=1;j<cnt;++j)nex[a[j]]=a[j+1];nex[a[cnt]]=n+1;
		head[tot]=a[1];
		d[tot]=size[ed[i]]*2;
		vec[d[tot]].push_back(tot);
	}
	for(i=1;i<=n+1;++i)fa[i]=i;
	for(i=1;i<=n;++i)Min[l+i-1]=i;
	for(i=l-1;i;--i)update(i);
	for(i=1;i<=n;++i)
	{
		
		cnt=0;
		for(j=vec[n-i+1].size()-1;j>=0;--j)
		{
			u=vec[n-i+1][j];
			if(d[u]==n-i+1)a[++cnt]=u;
		}
		u=0;
		if(cnt)
		{
			for(j=1;j<=cnt;++j)
			if(belong[i]!=a[j])break;
			if(j<=cnt)u=get(head[a[j]]);
		}
		if(!u)
		{
			if(i==root)u=Min[1];
			else
			{
				if(belong[Min[1]]==belong[i])u=Min_[1];
				else u=Min[1];
			}
		}
		if(belong[i])--d[belong[i]],vec[d[belong[i]]].push_back(belong[i]);
		if(belong[u])--d[belong[u]],vec[d[belong[u]]].push_back(belong[u]);
		Min[l+u-1]=0;
		for(j=l+u-1>>1;j;j>>=1)update(j);
		fa[u]=nex[u];
		printf("%d ",u);
	}
	printf("\n");
}