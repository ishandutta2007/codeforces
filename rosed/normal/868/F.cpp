#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10;
	typedef long long ll;
	int n,m;
	int a[N],c[N];
	ll ff[N],gg[N],*f=ff,*g=gg;
	inline void solve(int l,int r,int tl,int tr,ll w)
	{
		if(l>r) return;
		int mid=(l+r)>>1,k=0,p=mid<tr?mid:tr;
		for(int i=l;i<=mid;++i) w+=c[a[i]]++;
		for(int i=tl;i<=p;++i) w-=--c[a[i]],g[mid]>f[i]+w?g[mid]=f[i]+w,k=i:0;
		for(int i=tl;i<=p;++i) w+=c[a[i]]++;
		for(int i=l;i<=mid;++i) w-=--c[a[i]];
		solve(l,mid-1,tl,k,w);
		for(int i=l;i<=mid;++i)w+=c[a[i]]++;
		for(int i=tl;i<k;++i)  w-=--c[a[i]];
		solve(mid+1,r,k,tr,w);
		for(int i=tl;i<k;++i)  ++c[a[i]];
		for(int i=l;i<=mid;++i)--c[a[i]];
	}
	inline void main()
	{
		n=read(),m=read();
		ll *tmp;
		for(int i=1;i<=n;++i)
			f[i]=f[i-1]+c[a[i]=read()]++;
		memset(c,0,(n+1)<<2);
		while(--m)
		{
			memset(g,1,(n+1)<<3);
			solve(1,n,1,n,0);
			tmp=f,f=g,g=tmp;
		}
		printf("%lld\n",f[n]);
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
13 4
1 2 2 2 1 2 1 1 1 2 2 1 1


*/