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
int n,k,l,r,a[500001],lst[1000001],nxt[500001],t[4000001];
int ls(int x){return (x<<1);};
int rs(int x){return ls(x)|1;};
void build(int x,int l,int r)
{
	if(l==r-1)
	{
		t[x]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid,r);
	t[x]=t[ls(x)]+t[rs(x)];
}
void add(int x,int l,int r,int pos,int val)
{
	if(l==r-1)
	{
		t[x]=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<mid)
		add(ls(x),l,mid,pos,val);
	else
		add(rs(x),mid,r,pos,val);
	t[x]=t[ls(x)]+t[rs(x)];
}
int query(int x,int l,int r,int k)
{
	if(l==r-1)
		return l;
	int mid=(l+r)>>1;
	if(k<t[ls(x)])
		return query(ls(x),l,mid,k);
	return query(rs(x),mid,r,k-t[ls(x)]);
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=0;i<=1e6;i++)
		lst[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		a[i]=0;
	for(int i=0;i<=1e6;i++)
		if(lst[i]!=n+1)
			a[lst[i]]=1;
	build(1,1,n+2);
	for(int i=1;i<=n;i++)
	{
		int j=query(1,1,n+2,k);
		if(j-i>r-l)
		{
			r=j; 
			l=i;
		}
		add(1,1,n+2,i,0);
		if(nxt[i]!=n+1)
			add(1,1,n+2,nxt[i],1);
	}
	cout<<l<<" "<<r-1<<endl;
	return 0;
}