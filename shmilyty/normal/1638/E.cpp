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
const int N=1e6+5;
int n,q,val[N],t[N<<2],col[N<<2];
char s[10];
void push_down(int x)
{
	int k=t[x];
	t[x]=0;
	t[x<<1]+=k;
	t[x<<1|1]+=k;
	if(col[x])
	{
		k=col[x];
		col[x]=0;
		col[x<<1]=k;
		col[x<<1|1]=k;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		col[l]=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void modify1(int x,int l,int r,int L,int R,int c)
{
	if(L<=l&&r<=R)
	{
		col[x]=c;
		return ;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=L)
		modify1(x<<1,l,mid,L,R,c);
	if(mid<R)
		modify1(x<<1|1,mid+1,r,L,R,c);
}
void modify2(int x,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		t[x]+=v;
		return ;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=L)
		modify2(x<<1,l,mid,L,R,v);
	if(mid<R)
		modify2(x<<1|1,mid+1,r,L,R,v);
}
void modify3(int x,int l,int r,int L,int R,int c)
{
	if(col[x])
	{
//		if(c==3)
//			cout<<l<<" "<<r<<" "<<col[x]<<endl;
		modify2(x,l,r,L,R,val[col[x]]-val[c]);
		return ;
	}
	if(l==r)
		return ;
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=L)
		modify3(x<<1,l,mid,L,R,c);
	if(mid<R)
		modify3(x<<1|1,mid+1,r,L,R,c);
}
int query(int x,int l,int r,int k)
{
	if(l==r)
		return t[x]+val[col[x]];
	push_down(x);
	int mid=(l+r)>>1;
	if(k<=mid)
		return query(x<<1,l,mid,k);
	return query(x<<1|1,mid+1,r,k); 
}
signed main()
{
	n=read();
	q=read();
	build(1,1,n);
	while(q--)
	{
		scanf("%s",s+1); 
		if(s[1]=='C')
		{
			int l=read(),r=read(),c=read();
			modify3(1,1,n,l,r,c);
//		for(int i=1;i<=n;i++)
//			cout<<query(1,1,n,i)<<" ";
//		cout<<endl;
			modify1(1,1,n,l,r,c);
		}
		if(s[1]=='A')
		{
			int x=read(),y=read();
			val[x]+=y;
		}
		if(s[1]=='Q')
		{
			int x=read();
			cout<<query(1,1,n,x)<<'\n';
		}
//		for(int i=1;i<=n;i++)
//			cout<<query(1,1,n,i)<<" ";
//		cout<<endl;
	}
	return 0;
}