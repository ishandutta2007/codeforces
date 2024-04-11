#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,opt,u,v,ll,rr,key,ans1,ans2;
int son[500005],next[1000005],ed[1000005],tot;
int Max1[2000005],Max2[2000005];
int st[500005],en[500005];

void dfs(int x)
{
	st[x]=++tot;
	for(int i=son[x];i;i=next[i])
	if(!st[ed[i]])dfs(ed[i]);
	en[x]=tot;
}

void C(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		Max1[p]=key;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)C(p<<1,l,mid);
	else if(ll>mid)C(p<<1|1,mid+1,r);
		else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
}

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		if(Max2[p]>ans2)ans2=Max2[p];
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(p<<1,l,mid);
	else if(ll>mid)Q(p<<1|1,mid+1,r);
		else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
}

int main()
{
	scanf("%d",&n);
	for(l=1;l<n;l*=2);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	tot=0;
	dfs(1);
	scanf("%d",&m);
	for(;m;--m)
	{
		++key;
		scanf("%d%d",&opt,&u);
		ll=st[u];rr=en[u];
		if(opt==1)C(1,1,l);
		if(opt==2)for(i=l+st[u]-1;i;i>>=1)Max2[i]=key;
		if(opt==3)
		{
			ans1=ans2=0;
			for(i=l+st[u]-1;i;i>>=1)if(Max1[i]>ans1)ans1=Max1[i];
			Q(1,1,l);
			if(ans1>ans2)printf("1\n");
			else printf("0\n");
		}
	} 
}