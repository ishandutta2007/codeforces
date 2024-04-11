#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
struct node{
	int to,nxt;
}edge[100001];
int n,cnt,rt,s,k,tot,res,head[50001],sz[50001],mx[50001],vis[50001],dis[50001],ans[501];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void find(int x,int fa)
{
	sz[x]=1;
	mx[x]=0;
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to!=fa&&!vis[edge[i].to])
		{
			find(edge[i].to,x);
			sz[x]+=sz[edge[i].to];
			mx[x]=max(mx[x],sz[edge[i].to]);	
		} 
	mx[x]=max(mx[x],s-sz[x]);
	if(mx[x]<mx[rt])
		rt=x;
}
void getdis(int x,int fa,int len)
{
	if(len>k)
		return ;
	dis[tot++]=len;
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to!=fa&&!vis[edge[i].to])
			getdis(edge[i].to,x,len+1);
}
void solve(int x)
{
	for(int i=head[x];i;i=edge[i].nxt)
		if(!vis[edge[i].to])
		{
			int tmp=tot;
			getdis(edge[i].to,x,1);
			for(int l=tmp;l<tot;l++)
				res+=ans[k-dis[l]];
			for(int l=tmp;l<tot;l++)
				ans[dis[l]]++;
		}
	for(int i=0;i<tot;i++)
		ans[dis[i]]--;
	tot=0;
}
void divide(int x)
{
	ans[0]=1;
	solve(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].nxt)
		if(!vis[edge[i].to])
		{
			mx[rt=0]=n;
			s=sz[edge[i].to];
			find(edge[i].to,x);
			divide(rt);
		}
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	s=mx[0]=n;
	find(1,0);
	divide(rt);
	cout<<res; 
	return 0;
}