#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10;
	int haku,n;
	bool flag;
	int a[N],p[N];
	int f[N],s[N],ans[N<<2];
	inline int find(int k)
	{
		return f[k]==k?k:f[k]=find(f[k]);
	}
	inline void build(int l,int r,int p)
	{
		ans[p]=1;
		if(l==r) return;
		build(l,mid,ls(p));build(mid+1,r,rs(p));
	}
	inline void update(int pos,int l,int r,int p,int k)
	{
		if(l==r)
		{
			ans[p]=k;
			return;
		}
		if(pos<=mid) update(pos,l,mid,ls(p),k);
		if(pos>mid) update(pos,mid+1,r,rs(p),k);
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=read(),p[a[i]]=f[i]=i,s[i]=1;
			f[n+1]=n+1;
			build(1,n,1);
			flag=0;
			for(int i=1;i<=n;++i)
			{
				int x=find(p[i]);
				if(s[x]!=ans[1]||x!=p[i])
				{
					flag=1;
					break;
				}
				int y=find(x+1);
				f[x]=y;
				s[y]+=s[x];
				if(y<=n) update(y,1,n,1,s[y]);
				update(x,1,n,1,0);
			}
			puts(flag?"No":"Yes");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5
5
2 3 4 5 1
1
1
3
1 3 2
1
4
4 2 3 1

5
1 5 2 4 3

*/