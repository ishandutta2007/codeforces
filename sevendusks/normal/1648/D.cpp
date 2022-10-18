/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=5*1e5+100;
int n,q,sum[N][3],va[N],vb[N],ans;
struct node
{
	int l,r,k;
}sh[N];
bool cmp(node a,node b){return a.l<b.l;}
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg
{
	int MAX[N*4],tag[N*4],c[N*4],all[N*4],h;
	void pushup(int x)
	{
		MAX[x]=max(MAX[ls],MAX[rs]);
		all[x]=max(all[ls],all[rs]);
	}
	void pushdown(int x)
	{
		ckmax(MAX[ls],all[ls]+c[x]);ckmax(MAX[rs],all[rs]+c[x]);
		ckmax(MAX[ls],tag[x]);ckmax(tag[ls],tag[x]);
		ckmax(MAX[rs],tag[x]);ckmax(tag[rs],tag[x]);
		ckmax(MAX[rs],max(MAX[ls],all[ls])+c[x]);
		ckmax(tag[rs],max(MAX[ls],all[ls])+c[x]);
		ckmax(c[ls],c[x]);ckmax(c[rs],c[x]);
		c[x]=tag[x]=-inf;
	}
	void build(int x,int l,int r)
	{
		c[x]=tag[x]=MAX[x]=-inf;
		if (l==r){all[x]=va[l];return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r)
		{
			ckmax(MAX[x],all[x]+v);
			ckmax(MAX[x],h);ckmax(tag[x],h);
			ckmax(h,max(MAX[x],all[x])+v);
			ckmax(c[x],v);return;
		}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	int query(int x,int l,int r,int wh)
	{
		if (l==r) return MAX[x];
		int mid=(l+r)>>1;pushdown(x);
		if (wh<=mid) return query(ls,l,mid,wh);
		else return query(rs,mid+1,r,wh);
	}
	void dfs(int x,int l,int r)
	{
		if (l==r)
		{
			ckmax(ans,vb[l]+MAX[x]);
			return;
		}
		int mid=(l+r)>>1;pushdown(x);
		dfs(ls,l,mid);dfs(rs,mid+1,r);
	}
}
signed main()
{
	n=read();q=read();
	for (int j=0;j<3;j++)
	{
		for (int i=1;i<=n;i++) sum[i][j]=sum[i-1][j]+read();
	}
	for (int i=1;i<=q;i++) sh[i]=(node){read(),read(),read()};
	for (int i=1;i<=n;i++)
	{
		va[i]=sum[i][0]-sum[i-1][1];
		vb[i]=sum[n][2]-sum[i-1][2]+sum[i][1];
	}
	seg::build(1,1,n);
	sort(sh+1,sh+1+q,cmp);
	for (int i=1;i<=q;i++)
	{
		int l=sh[i].l,r=sh[i].r,k=sh[i].k;
		seg::h=(l==1?-inf:(seg::query(1,1,n,l-1)-k));
		seg::change(1,1,n,l,r,-k);
	}
	ans=-inf;
	seg::dfs(1,1,n);
	printf("%lld\n",ans);
}