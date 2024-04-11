/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int n,d,dp[N],b[N],w;
vector <int> p[N];
struct node
{
	int s,a;
}sh[N];
bool operator <(node a,node b){return a.a<b.a;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit
{
	int sh[N];
	inline int lowbit(int x){return x&(-x);}
	inline void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
	inline int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
}T;
namespace seg
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
		if (l==r)
		{
			MAX[x]=-inf;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r){tag[x]+=v,MAX[x]+=v;return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	void change_pos(int x,int l,int r,int wh,int v)
	{
		if (l==r)
		{
			MAX[x]=v;
			return;
		}
		int mid=(l+r)>>1;pushdown(x);
		if (wh<=mid) change_pos(ls,l,mid,wh,v);
		else change_pos(rs,mid+1,r,wh,v);
		pushup(x);
	}
	int query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r) return MAX[x];
		int mid=(l+r)>>1,ans=-inf;pushdown(x);
		if (ll<=mid) ans=max(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=max(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
signed main()
{
	n=read();d=read();
	for (int i=1;i<=n;i++) sh[i]=(node){read(),read()};
	sort(sh+1,sh+1+n);
	for (int i=1;i<=n;i++) b[++w]=sh[i].s,b[++w]=sh[i].a;
	b[++w]=d;
	sort(b+1,b+1+w);
	w=unique(b+1,b+1+w)-b-1;
	d=lower_bound(b+1,b+1+w,d)-b;
	for (int i=1;i<=n;i++)
	{
		sh[i].s=lower_bound(b+1,b+1+w,sh[i].s)-b;
		sh[i].a=lower_bound(b+1,b+1+w,sh[i].a)-b;
	}
	int pos=n+1,ans=0;
	memset(dp,-0x3f,sizeof(dp));
	for (int i=1;i<=n;i++)
	{
		if (sh[i].a<=d) ans+=(sh[i].s>=d);
		else{pos=i;break;}
	}
	if (pos==n+1)
	{
		printf("%d\n",ans);
		return 0;
	}
	rotate(sh+1,sh+pos,sh+n+1);
	int m=n-pos+1;
	for (int i=1;i<=m;i++) p[sh[i].s].push_back(i);
	seg::build(1,0,m);
	seg::change_pos(1,0,m,0,0);
	for (int i=1;i<=m;i++) T.change(i,1);
	int last=1,now=0;
	for (int i=1;i<=m;i++) if (sh[i].s>=d)
	{
		for (int j=last;j<sh[i].a;j++)
		{
			for (int k:p[j])
			{
				T.change(k,-1);
				seg::change(1,0,m,k,m,1);
			}
		}
		int pos=upper_bound(sh+1,sh+1+m,(node){0,sh[i].s})-sh-1;
		dp[i]=T.query(i-1)+seg::query(1,0,m,0,pos)+1;
		now=max(now,dp[i]);
		seg::change_pos(1,0,m,i,dp[i]-T.query(i));
		last=sh[i].a;
	}
	ans+=now;
	printf("%d\n",ans);
}