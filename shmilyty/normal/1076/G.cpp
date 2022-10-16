#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
struct node{
	int v[7];
}t[2][400001];
int n,m,q,cnt,rt,a[200001],L[400001],R[400001],tag[400001];
node up(node x,node y)
{
	node res;
	for(int l=1;l<=m+1;l++)
		res.v[l]=x.v[y.v[l]];
	return res;
}
void push(int x)
{
	swap(t[0][x],t[1][x]);
	tag[x]^=1;
}
void pushup(int x)
{
	t[0][x]=up(t[0][L[x]],t[0][R[x]]);
	t[1][x]=up(t[1][L[x]],t[1][R[x]]);
}
void pushdown(int x)
{
	push(L[x]);
	push(R[x]);
	tag[x]=0;
}
void build(int &x,int l,int r)
{
	if(!x)
		x=++cnt;
	if(l==r)
	{
		for(int i=1;i<=m;i++)
			t[0][x].v[i]=t[1][x].v[i]=i+1;
		t[a[l]][x].v[m+1]=1;
		t[!a[l]][x].v[m+1]=m+1;
		return ;
	}
	int mid=(l+r)>>1;
	build(L[x],l,mid);
	build(R[x],mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		push(x);
		return ;
	}
	if(tag[x])
		pushdown(x);
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(L[x],l,mid,ll,rr);
	if(mid<rr)
		modify(R[x],mid+1,r,ll,rr);
	pushup(x);
}
node query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return t[0][x];
	if(tag[x])
		pushdown(x);
	int mid=(l+r)>>1;
	if(mid>=rr)
		return query(L[x],l,mid,ll,rr);
	if(mid<ll)
		return query(R[x],mid+1,r,ll,rr);
	return up(query(L[x],l,mid,ll,rr),query(R[x],mid+1,r,ll,rr)); 
}
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=((read()-1)&1);
	build(rt,1,n);
	while(q--)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)
			if(read()&1)
				modify(rt,1,n,x,y);
		if(opt==2)
			cout<<1+(query(rt,1,n,x,y).v[m+1]==1)<<'\n'; 
	}
	return 0;
}