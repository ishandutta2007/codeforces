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
struct node
{
	int sum,pre,suf,val,l,r,p,s;
}t[400001],t1[400001];
std::vector<array<int,2>> v;
node operator+(node x,node y)
{
	node z={x.sum+y.sum,max(x.pre,y.pre+x.sum),max(x.suf+y.sum,y.suf),max({x.val,y.val,x.suf+y.pre})};
	if(z.pre==x.pre)
		z.p=x.p;
	else
		z.p=y.p;
	if(z.suf==y.suf)
		z.s=y.s;
	else
		z.s=x.s;
	if(z.val==x.val)
	{
		z.l=x.l;
		z.r=x.r;
	}
	elif(z.val==y.val)
	{
		z.l=y.l;
		z.r=y.r;
	}
	else
	{
		z.l=x.s;
		z.r=y.p;
	}
	return z;
}
int n,m,tag[400001];
void build(int x,int l,int r)
{
	if(l==r)
	{
		int k=read();
		t[x]={k,max(k,0ll),max(k,0ll),max(k,0ll),l,l,l,l};
		t1[x]={-k,max(-k,0ll),max(-k,0ll),max(-k,0ll),l,l,l,l};
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	build(xx,l,mid);
	build(xx|1,mid+1,r);
	t[x]=t[xx]+t[xx|1];
	t1[x]=t1[xx]+t1[xx|1];
}
void modify(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		t[x]={v,max(v,0ll),max(v,0ll),max(v,0ll),l,l,l,l};
		t1[x]={-v,max(-v,0ll),max(-v,0ll),max(-v,0ll),l,l,l,l};
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	if(tag[x])
	{
		tag[x]=0;
		swap(t[xx],t1[xx]);
		swap(t[xx|1],t1[xx|1]);
		tag[xx]^=1;
		tag[xx|1]^=1;
	}
	if(p<=mid)
		modify(xx,l,mid,p,v);
	else
		modify(xx|1,mid+1,r,p,v);
	t[x]=t[xx]+t[xx|1];
	t1[x]=t1[xx]+t1[xx|1];
}
void modify1(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		swap(t[x],t1[x]);
		tag[x]^=1;
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	if(tag[x])
	{
		tag[x]=0;
		swap(t[xx],t1[xx]);
		swap(t[xx|1],t1[xx|1]);
		tag[xx]^=1;
		tag[xx|1]^=1;
	}
	if(ll<=mid)
		modify1(xx,l,mid,ll,rr);
	if(mid<rr)
		modify1(xx|1,mid+1,r,ll,rr);
	t[x]=t[xx]+t[xx|1];
	t1[x]=t1[xx]+t1[xx|1];
}
node query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return t[x];
	int mid=(l+r)>>1,xx=x<<1;
	if(tag[x])
	{
		tag[x]=0;
		swap(t[xx],t1[xx]);
		swap(t[xx|1],t1[xx|1]);
		tag[xx]^=1;
		tag[xx|1]^=1;
	}
	if(ll<=mid&&mid<rr)
		return query(xx,l,mid,ll,rr)+query(xx|1,mid+1,r,ll,rr);
	if(ll<=mid)
		return query(xx,l,mid,ll,rr);
	return query(xx|1,mid+1,r,ll,rr);
}
signed main()
{
	n=read();
	build(1,1,n);
	m=read();
	while(m--)
	{
		int opt=read();
		if(!opt)
		{
			int x=read(),y=read();
			modify(1,1,n,x,y);
		}
		else
		{
			int l=read(),r=read(),k=read(),res=0;
			v.clear();
			while(k--)
			{
				node p=query(1,1,n,l,r);
				if(!p.val)
					break;
				res+=p.val;
				v.push_back({p.l,p.r});
				modify1(1,1,n,p.l,p.r);
			}
			cout<<res<<'\n';
			for(auto i:v)
				modify1(1,1,n,i[0],i[1]);
		}
	}
	return 0;
}