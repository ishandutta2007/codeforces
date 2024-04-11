#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-')f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e6+10;
	int aa,bb,tot,n,m,pre;
	int f[N],g[N];
	int ret,w;
	int st[N],top;
	struct node
	{
		int x,y,id;
		inline bool operator < (const node &t) const
		{
			return x<t.x;
		}
	}a[N];
	int ans[N<<2],pos[N<<2];
	inline void update(int d,int l,int r,int p,int k,int w)
	{
		if(l==r)
		{
			if(k>ans[p])
			{
				ans[p]=k;
				pos[p]=w;
			}
			return;
		}
		if(d<=mid) update(d,l,mid,ls(p),k,w);
		else update(d,mid+1,r,rs(p),k,w);
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
		pos[p]=ans[ls(p)]>=ans[rs(p)]?pos[ls(p)]:pos[rs(p)];
	}
	inline node query(int tl,int tr,int l,int r,int p)
	{
		if(!tr) return (node){0,0};
		if(tl<=l&&r<=tr) return (node){ans[p],pos[p]};
		if(tr<=mid) return query(tl,tr,l,mid,ls(p));
		if(tl>mid) return query(tl,tr,mid+1,r,rs(p));
		node tx=query(tl,tr,l,mid,ls(p)),ty=query(tl,tr,mid+1,r,rs(p));
		return tx.x>=ty.x?tx:ty;
	}
	inline void main()
	{
		tot=read(),aa=read(),bb=read();
		for(int x,y,i=1;i<=tot;++i)
		{
			x=read(),y=read();
			if(x<=aa||y<=bb) continue;
			a[++n].x=x,a[n].y=y,a[n].id=i;
			m=max(m,a[n].y);
		}
		if(!n)
		{
			puts("0");
			return;
		}
		sort(a+1,a+n+1);
		pre=1;
		for(int i=1;i<=n;++i)
		{
			if(a[i].x^a[i-1].x)
			{
				for(int j=pre;j<=i-1;++j) update(a[j].y,1,m,1,f[j],j);
				pre=i;
			}
			node t=query(1,a[i].y-1,1,m,1);
			f[i]=f[t.y]+1;
			g[i]=t.y;
			if(f[i]>ret) ret=f[i],w=i;
		}
		printf("%d\n",ret);
		while(w) st[++top]=a[w].id,w=g[w];
		while(top) printf("%d ",st[top--]);
	}
}
signed main()
{
	red::main();
	return 0;
}