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
	const int N=1e6+10,inf=1e12;
	int haku;
	int n,m,k,ret=-inf;
	struct node
	{
		int val,c;
		inline bool operator < (const node &t) const
		{
			return val<t.val;
		}
	}a[N],b[N];
	struct point
	{
		int x,y,z;
		inline bool operator < (const point &t) const
		{
			return x<t.x;
		}
	}g[N];
	int ans[N<<2],tag[N<<2];
	inline void pushdown(int p)
	{
		ans[ls(p)]+=tag[p];
		ans[rs(p)]+=tag[p];
		tag[ls(p)]+=tag[p];
		tag[rs(p)]+=tag[p];
		tag[p]=0;
	}
	inline void update(int tl,int tr,int l,int r,int p,int k)
	{
		if(tl<=l&&r<=tr)
		{
			ans[p]+=k;
			tag[p]+=k;
			return;
		}
		if(tag[p]) pushdown(p);
		if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
		if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
	}
	inline int erfen(int x,int m)
	{
		int l=1,r=m,ans=m+1;
		while(l<=r)
		{
			if(b[mid].val<=x) l=mid+1;
			else ans=mid,r=mid-1;
		}
		return ans;
	}
	inline void main()
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i) a[i].val=read(),a[i].c=read();
		sort(a+1,a+n+1);
		int nn=n,n=0;
		for(int i=1;i<=nn;++i)
		{
			while(a[i].c<=a[n].c&&n) --n;
			a[++n]=a[i];
		}
		for(int i=1;i<=m;++i) b[i].val=read(),b[i].c=read();
		sort(b+1,b+m+1);
		int mm=m,m=0;
		for(int i=1;i<=mm;++i)
		{
			while(b[i].c<=b[m].c&&m) --m;
			b[++m]=b[i];
		}
		for(int i=1;i<=k;++i) g[i].x=read(),g[i].y=read(),g[i].z=read();
		sort(g+1,g+k+1);
		int t=1;
		for(int i=1;i<=m;++i) update(i,i,1,m,1,-b[i].c);
		for(int i=1;i<=n;++i)
		{
			while(g[t].x<a[i].val&&t<=k)
			{
				int pos=erfen(g[t].y,m);
				if(pos<=m) update(pos,m,1,m,1,g[t].z);
				++t;
			}
			ret=max(ret,ans[1]-a[i].c);
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}