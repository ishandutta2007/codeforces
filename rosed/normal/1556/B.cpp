#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=1e5+10;
	int T,n,m,ret;
	int a[N],b[N];
	int num[2];
	int ans[N<<2][2];
	inline void build(int l,int r,int p)
	{
		if(l==r)
		{
			ans[p][a[l]]=l;
			ans[p][a[l]^1]=0;
			return;
		} 
		build(l,mid,ls(p));
		build(mid+1,r,rs(p));
		ans[p][0]=max(ans[ls(p)][0],ans[rs(p)][0]);
		ans[p][1]=max(ans[ls(p)][1],ans[rs(p)][1]);
	}
	inline void update(int l,int r,int p,int pos)
	{
		if(l==r)
		{
			ans[p][a[l]]=l;
			ans[p][a[l]^1]=0;
			return;
		}
		if(pos<=mid) update(l,mid,ls(p),pos);
		if(pos>mid) update(mid+1,r,rs(p),pos);
		ans[p][0]=max(ans[ls(p)][0],ans[rs(p)][0]);
		ans[p][1]=max(ans[ls(p)][1],ans[rs(p)][1]);
	}
	inline int query(int l,int r,int p,int pos,int k)
	{
		if(l==r) return l;
		if(ans[ls(p)][k]>=pos) return query(l,mid,ls(p),pos,k);
		return query(mid+1,r,rs(p),pos,k); 
	}
	inline int work(int bit)
	{
		int sum=0;
		for(int i=1;i<=n;++i) a[i]=b[i];
		build(1,n,1);
		for(int pos,i=1;i<=n;++i,bit^=1)
		{
			if(a[i]!=bit)
			{
				pos=query(1,n,1,i+1,bit);
				sum+=pos-i;
				swap(a[pos],a[i]);
				update(1,n,1,i);update(1,n,1,pos);
			}
		}
		return sum;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();num[0]=num[1]=1;
			for(int i=1;i<=n;++i)
			{
				b[i]=read()&1;
				++num[b[i]];
			}
			if(abs(num[0]-num[1])>1)
			{
				puts("-1");
				continue;
			}
			if(num[0]<num[1]) printf("%d\n",work(1));
			else if(num[0]>num[1]) printf("%d\n",work(0));
			else printf("%d\n",min(work(0),work(1)));
		}
	}
}
signed main()
{
	red::main();
	return 0;
}