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
int TC,n,m,a[N],b[N],c[N*2],w;
vector <int> p[N*2];
long long ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit
{
	int sh[N*2];
	void clear(int w){memset(sh,0,(w+10)*sizeof(int));}
	inline int lowbit(int x){return x&(-x);}
	inline void change(int x,int v){while(x)sh[x]+=v,x-=lowbit(x);}
	inline int query(int x){int ans=0;while(x<=w)ans+=sh[x],x+=lowbit(x);return ans;}
}T;
namespace seg
{
	int tag[N*4];
	pair<int,int> MIN[N*4];
	inline void pushup(int x){MIN[x]=min(MIN[ls],MIN[rs]);}
	void pushdown(int x)
	{
		tag[ls]+=tag[x];tag[rs]+=tag[x];
		MIN[ls].first+=tag[x];MIN[rs].first+=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r)
	{
		tag[x]=0;
		if (l==r)
		{
			MIN[x]=m_k(l,l);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r){tag[x]+=v,MIN[x].first+=v;return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	pair<int,int> query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r)return MIN[x];
		int mid=(l+r)>>1;pushdown(x);
		pair<int,int> ans=m_k(inf,0);
		if (ll<=mid) ans=min(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=min(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
signed main()
{
	TC=read();
	while(TC--)
	{
		n=read();m=read();w=0;
		for (int i=1;i<=n;i++) a[i]=read(),c[++w]=a[i];
		for (int i=1;i<=m;i++) b[i]=read(),c[++w]=b[i];
		sort(c+1,c+1+w);
		w=unique(c+1,c+1+w)-c-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+1+w,a[i])-c;
		for (int i=1;i<=m;i++) b[i]=lower_bound(c+1,c+1+w,b[i])-c;
		sort(b+1,b+1+m);
		for (int i=1;i<=w;i++) p[i].clear();
		for (int i=1;i<=n;i++) p[a[i]].push_back(i);
		seg::build(1,0,n);
		b[0]=0;
		ans=0;
		for (int i=1;i<=m;i++)
		{
			for (int j=b[i-1];j<b[i];j++)
			{
				for (int k:p[j])
				{
					if (j!=b[i-1]) seg::change(1,0,n,k,n,-1);
					seg::change(1,0,n,0,k-1,1);
				}
			}
			if (b[i]!=b[i-1]) for (int k:p[b[i]]) seg::change(1,0,n,k,n,-1);
			ans+=seg::MIN[1].first;
		}
		T.clear(w);
		for (int i=1;i<=n;i++) ans+=T.query(a[i]+1),T.change(a[i],1);
		printf("%lld\n",ans);
	}
}