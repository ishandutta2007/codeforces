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
const int N=5*1e4+100;
int T,n,a[N],x,ok[N],dp[N],pre[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg//min
{
	int tag[N*4],MIN[N*4];
	inline void pushup(int x){MIN[x]=min(MIN[ls],MIN[rs]);}
	void pushdown(int x)
	{
		tag[ls]+=tag[x];tag[rs]+=tag[x];
		MIN[ls]+=tag[x];MIN[rs]+=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r)
	{
		tag[x]=0;
		if (l==r){MIN[x]=0;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r){tag[x]+=v,MIN[x]+=v;return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	int query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r)return MIN[x];
		int mid=(l+r)>>1;pushdown(x);
		int ans=inf;
		if (ll<=mid) ans=min(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=min(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
namespace ment
{
	int tag[N*4],MAX[N*4];
	inline void pushup(int x){MAX[x]=max(MAX[ls],MAX[rs]);}
	void pushdown(int x)
	{
		tag[ls]+=tag[x];tag[rs]+=tag[x];
		MAX[ls]+=tag[x];MAX[rs]+=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r)
	{
		tag[x]=0;
		if (l==r){MAX[x]=0;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int wh,int v)
	{
		if (l==r){MAX[x]=v;return;}
		int mid=(l+r)>>1;pushdown(x);
		if (mid<=wh) change(ls,l,mid,wh,v);
		else change(rs,mid+1,r,wh,v);
		pushup(x);
	}
	int query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r)return MAX[x];
		int mid=(l+r)>>1,ans=-inf;pushdown(x);
		if (ll<=mid) ans=max(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=max(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		x=read();
		for (int i=1;i<=n;i++) a[i]-=x;
		seg::build(1,1,n);
		ok[1]=1;seg::change(1,1,n,1,1,a[1]);
		for (int i=2;i<=n;i++)
		{
			seg::change(1,1,n,1,i,a[i]);
			ok[i]=ok[i-1];
			while (ok[i]<i&&seg::query(1,1,n,ok[i],i-1)<0) ok[i]++;
		}
		// for (int i=1;i<=n;i++) printf("%lld ",ok[i]);
		// printf("\n");
		dp[0]=0;dp[1]=pre[1]=1;
		ment::build(1,0,n);
		ment::change(1,0,n,0,0);
		for (int i=2;i<=n;i++)
		{
			dp[i]=ment::query(1,0,n,max(0ll,ok[i]-2),i-2)+i;
			if (ok[i]>=2) dp[i]=min(dp[i],pre[ok[i]-2]+i-ok[i]+1);
			pre[i]=max(pre[i-1],dp[i]);
			ment::change(1,0,n,i,dp[i]-i);
		}
		printf("%lld\n",*max_element(dp+1,dp+1+n));
	}
}