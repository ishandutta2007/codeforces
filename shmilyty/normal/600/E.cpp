#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,c[100001],head[100001],dep[100001],son[100001],size[100001];
int ap[100001],sum,maxx,ans[100001];
struct node{
	int to,next;
} edge[200001];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs1(int x,int fa)
{
	int heavy=-1;
	size[x]=1;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			dfs1(edge[i].to,x);
			size[x]+=size[edge[i].to];
			if(heavy<size[edge[i].to])	
			{
				heavy=size[edge[i].to];
				son[x]=edge[i].to;
			}
		}
}
void dfs2(int x,int f,int p)
{
	ap[c[x]]++;
	if(ap[c[x]]>maxx)
	{
		maxx=ap[c[x]];
		sum=c[x];
	}
	else
	if(ap[c[x]]==maxx)
		sum+=c[x];
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=f&&edge[i].to!=p)
			dfs2(edge[i].to,x,p);
}
void Init(int x,int f)
{
	ap[c[x]]--;
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=f)
			Init(edge[i].to,x);
}
void dfs(int x,int f)
{
	int p=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)
			continue;
		if(y!=son[x])
		{
			dfs(y,x);
			Init(y,x);
			sum=maxx=0;
		}
		else 
			p=y;
	}
	if(p)
		dfs(p,x);
	dfs2(x,f,p);
	ans[x]=sum;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%lld%lld",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs1(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";//1
	return 0;
}