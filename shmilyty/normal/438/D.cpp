#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
int n,m,a[100001],mx[400001],tag[400001];
long long t[400001];
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=mx[x]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void modify1(int x,int l,int r,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		if(v==1)
		{
			mx[x]=t[x]=0;
			tag[x]=1;
			return ;
		}
		elif(mx[x]<v)
			return ;
	}
	if(l==r)
	{
		t[x]%=v;
		mx[x]=t[x];
		return ;
	}
	if(tag[x])
	{
		tag[x]=0;
		tag[x<<1|1]=tag[x<<1]=1;
		t[x<<1]=t[x<<1|1]=0;
		mx[x<<1]=mx[x<<1|1]=0;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify1(x<<1,l,mid,ll,rr,v);
	if(mid<rr)
		modify1(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=t[x<<1]+t[x<<1|1];
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void modify2(int x,int l,int r,int k,int v)
{
	if(l==r)
	{
		t[x]=mx[x]=v;
		return ;
	}
	if(tag[x])
	{
		tag[x]=0;
		tag[x<<1|1]=tag[x<<1]=1;
		t[x<<1]=t[x<<1|1]=0;
		mx[x<<1]=mx[x<<1|1]=0;
	}
	int mid=(l+r)>>1;
	if(k<=mid)
		modify2(x<<1,l,mid,k,v);
	else
		modify2(x<<1|1,mid+1,r,k,v);
	t[x]=t[x<<1]+t[x<<1|1];
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return t[x];
	if(tag[x])
	{
		tag[x]=0;
		tag[x<<1|1]=tag[x<<1]=1;
		t[x<<1]=t[x<<1|1]=0;
		mx[x<<1]=mx[x<<1|1]=0;
		return 0;
	}
	int mid=(l+r)>>1,res=0;
	if(mid>=ll)
		res+=query(x<<1,l,mid,ll,rr);
	if(mid<rr)
		res+=query(x<<1|1,mid+1,r,ll,rr);
	return res;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read();
			cout<<query(1,1,n,l,r)<<'\n';
		}
		elif(opt==2)
		{
			int l=read(),r=read(),v=read();
			modify1(1,1,n,l,r,v);
		}
		else
		{
			int x=read(),v=read();
			modify2(1,1,n,x,v);
		}
	}
	return 0;
}