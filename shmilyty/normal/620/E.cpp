#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
inline int read()
{
	int x=0;
	bool flag=1;
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
}edge[800001];
int n,cnt,q,rk[400001],in[400001],out[400001],head[400001],c[400001],t[1600001],lazy[1600001];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void push_down(int x)
{
	if(!lazy[x])
		return ;
	lazy[x*2]=lazy[x*2+1]=lazy[x];
	t[x*2]=t[x*2+1]=(1LL<<lazy[x]);
	lazy[x]=0;
} 
void dfs(int x)
{
	in[x]=++cnt;
	rk[cnt]=x;
	for(int i=head[x];i;i=edge[i].nxt)
		if(!in[edge[i].to])
			dfs(edge[i].to);
	out[x]=cnt; 
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=(1LL<<c[rk[l]]);
		return ;
	}
	int mid=(l+r)>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	t[x]=t[x*2]|t[x*2+1];
}
void modify(int x,int l,int r,int ll,int rr,int v)
{
	if(ll<=l&&r<=rr)
	{
		t[x]=(1LL<<v);
		lazy[x]=v;
		return ;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(ll<=mid)
		modify(x*2,l,mid,ll,rr,v);
	if(rr>mid)
		modify(x*2+1,mid+1,r,ll,rr,v);
	t[x]=t[x*2]|t[x*2+1];
}
int query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return t[x];
	push_down(x);
	int mid=(l+r)>>1;
	int ans=0;
	if(ll<=mid)
		ans|=query(x*2,l,mid,ll,rr);
	if(rr>mid)
		ans|=query(x*2+1,mid+1,r,ll,rr);
	return ans;
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	cnt=0;
	dfs(1);
	build(1,1,n);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),y=read();
//			cout<<in[x]<<" "<<out[x]<<endl;
			modify(1,1,n,in[x],out[x],y);
		}
		else
		{
			int x=read();
			int ans=query(1,1,n,in[x],out[x]),res=0;
//			cout<<in[x]<<" "<<out[x]<<" "<<ans<<endl;
			while(ans)
			{
				res+=ans%2;
				ans/=2;
			}
			cout<<res<<endl; 
		}
	}
	return 0;
}