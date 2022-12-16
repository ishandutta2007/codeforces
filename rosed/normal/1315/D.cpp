#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=2e5+10,mod=1e9+7;
	int haku;
	int n,nn=1e5,ret;
	map<int,int> nxt;
	struct node
	{
		int x,t;
		inline bool operator < (const node &y) const
		{
			return x==y.x?t>y.t:x<y.x;
		}
	}a[N];
	struct point
	{
		int l,r,s;
	}link[N];
	int tot;
	int sum[N<<2];
	int s[N];
	inline void update(int pos,int l,int r,int p,int k)
	{
		sum[p]+=k;
		if(l==r) {return;}
		if(pos<=mid) update(pos,l,mid,ls(p),k);
		else update(pos,mid+1,r,rs(p),k);
	}
	inline int query(int l,int r,int p)
	{
		if(l==r) return l;
		if(sum[rs(p)]) return query(mid+1,r,rs(p));
		return query(l,mid,ls(p)); 
	}
	int tr[N];
	inline int lowbit(int i){return i&-i;}
	inline void updatebit(int x,int k)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			tr[i]+=k;
	}
	inline int querybit(int y)
	{
		int ret=1;
		for(int i=y;i;i-=lowbit(i))
			ret+=tr[i];
		return ret;
	}
	inline void main()
	{
		n=read();ret=0;
		for(int i=1;i<=n;++i) a[i].x=read();
		for(int i=1;i<=n;++i) a[i].t=read();
		sort(a+1,a+n+1);
		a[n+1].x=0;
		for(int i=n;i;--i)
		{
			if(a[i].x!=a[i+1].x) nxt[a[i].x]=i;
		}
		for(int i=1;i<=n;++i)
		{
			updatebit(i,a[i].t);
		}
		int idx=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i].x!=a[i-1].x)
			{
				link[++idx]=(point){i,nxt[a[i].x],nxt[a[i].x]-i+1};
			}
		}
		int t=1;
		for(int i=link[t].l;i<=link[t].r;++i) update(a[i].t,1,nn,1,1);
		while(t<=idx)
		{
			int l=link[t].l,r=link[t].r;
			int tmp=query(1,nn,1);
			if(link[t].s>1)
			{
				--link[t].s;
				ret+=querybit(r)-querybit(l-1)-tmp;
				++a[l].x;
				if(a[l].x==a[r+1].x)
				{
					for(int i=link[t+1].l;i<=link[t+1].r;++i) update(a[i].t,1,nn,1,1);
					link[t+1].l=link[t].l,link[t+1].s+=link[t].s,++t;
				}
				updatebit(l,-tmp);
			}
			else
			{
				++t;
				for(int i=link[t].l;i<=link[t].r;++i) update(a[i].t,1,nn,1,1);
			}
			update(tmp,1,nn,1,-1);
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}