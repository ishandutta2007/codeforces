#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;
int n,q;
ll tmp[MAXN];
string str;
void in(int &x)
{
    int ff=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=ff;
}
struct segtree
{
	int lazy[4*MAXN];
	ll add[4*MAXN];
	void pushdown_lazy(int k)
	{
		if(lazy[k])
		{
			for(int i=k*2;i<=k*2+1;i++) lazy[i]=lazy[k];
			lazy[k]=0;
		}
		
	}
	void pushdown_add(int k)
	{
		if(add[k])
		{
			for(int i=k*2;i<=k*2+1;i++)  add[i]+=add[k];
			add[k]=0;
		}
	}
	void update(int k,int l,int r,int x,int y,int c)
	{
		if(l>y||x>r) return;
		if(l>=x&&r<=y) 
		{
			lazy[k]=c;
			return;
		}
		pushdown_lazy(k);
		int mid=(l+r)/2;
		update(k*2,l,mid,x,y,c); update(k*2+1,mid+1,r,x,y,c);
	}
	void update_add(int k,int l,int r,int x,int y,ll v)
	{
		if(l>y||x>r) return;
		if(l>=x&&r<=y) 
		{
			add[k]+=v;
			return;
		}
		int mid=(l+r)/2;
		update_add(k*2,l,mid,x,y,v); update_add(k*2+1,mid+1,r,x,y,v);
	}
	void update_color_add(int k,int l,int r,int x,int y,int c)
	{
		if(l>y||x>r) return;
		if(lazy[k])
		{
			update_add(k,l,r,x,y,tmp[lazy[k]]-tmp[c]);
			return;
		}
		if(l==r) return;
		int mid=(l+r)/2;
		update_color_add(k*2,l,mid,x,y,c); update_color_add(k*2+1,mid+1,r,x,y,c);
	}
	ll query(int k,int l,int r,int pos)
	{
		if(l==r) return add[k]+tmp[lazy[k]];
		pushdown_lazy(k);
		pushdown_add(k);
		int mid=(l+r)/2;
		if(pos<=mid) return query(k*2,l,mid,pos); else return query(k*2+1,mid+1,r,pos);
	}
}seg;
int main()
{
	in(n); in(q);
	seg.lazy[1]=1;
	for(int i=1;i<=q;i++)
	{
		cin>>str;
		int l,r,c,x;
		if(str=="Color")
		{
			in(l); in(r); in(c);
			seg.update_color_add(1,1,n,l,r,c);
			seg.update(1,1,n,l,r,c);
		}
		else if(str=="Add")
		{
			in(c); in(x);
			tmp[c]+=x;
		}
		else 
		{
			in(x);
			printf("%lld\n",seg.query(1,1,n,x));
		}
	}
	return 0;
}