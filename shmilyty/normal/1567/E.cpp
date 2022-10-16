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
	int pre,suf,tot,l,r,con;
	node()
	{
		pre=suf=tot=l=r=con=0;
	}
}t[1<<19];
int n,q,a[200001];
int calc(int x)
{
	return x*(x+1)/2;
}
node com(node x,node y)
{
	if(!x.l)
		return y;
	if(!y.l)
		return x;
	node ans;
	ans.l=x.l;
	ans.r=y.r;
	if(x.con&&y.con)
	{
		ans.tot=0;
		if(x.r<=y.l)
		{
			ans.pre=ans.suf=x.pre+y.pre;
			ans.con=1; 
		}
		else
		{
			ans.pre=x.pre;
			ans.suf=y.suf;
		}
		return ans;
	}
	ans.tot=x.tot+y.tot;
	if(x.con)
	{
		ans.suf=y.suf;
		if(x.r<=y.l)
			ans.pre=x.pre+y.pre;
		else
		{
			ans.pre=x.pre;
			ans.tot+=calc(y.pre);
		}
		return ans;
	}
	if(y.con)
	{
		ans.pre=x.pre;
		if(x.r<=y.l)
			ans.suf=y.suf+x.suf;
		else
		{
			ans.suf=y.suf;
			ans.tot+=calc(x.suf);
		}
		return ans;
	}
	ans.pre=x.pre;
	ans.suf=y.suf;
	if(x.r<=y.l)
		ans.tot+=calc(x.suf+y.pre);
	else
		ans.tot+=calc(x.suf)+calc(y.pre);
	return ans;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x].pre=t[x].suf=1;
		t[x].l=t[x].r=a[l];
		t[x].con=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=com(t[x<<1],t[x<<1|1]);
}
void modify(int x,int l,int r,int y,int v)
{
	if(l==r)
	{
		t[x].l=t[x].r=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=y)
		modify(x<<1,l,mid,y,v);
	else
		modify(x<<1|1,mid+1,r,y,v);
	t[x]=com(t[x<<1],t[x<<1|1]);
}
node query(int x,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)
		return t[x];
	int mid=(l+r)>>1;
	node ans;
	if(mid>=L)
		ans=com(ans,query(x<<1,l,mid,L,R));
	if(R>mid)
		ans=com(ans,query(x<<1|1,mid+1,r,L,R));
	return ans;
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
//	/*
	while(q--)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)
			modify(1,1,n,x,y);
		else
		{
			node z=query(1,1,n,x,y);
			if(z.con)
				cout<<calc(z.pre)<<endl;
			else
				cout<<z.tot+calc(z.pre)+calc(z.suf)<<endl;
		}
	}
//	*/
	return 0;
}