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
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T,n,nn,ans; 
	int a[N],c[N],num,pre[N],suf[N];
	int d[N],up[N],bf;
	inline void main()
	{
		T=read();bf=1;
		for(int i=0;i<=200000;++i)
		{
			if(i>bf) bf<<=1;
			d[i]=bf-i,up[i]=bf;
		}
		while(T--)
		{
			n=nn=read();ans=d[n]+2;
			for(int i=1;i<=n;++i) a[i]=read(),pre[i]=suf[i]=0;suf[n+1]=0;
			sort(a+1,a+n+1);int sum=1;num=0;
			for(int i=2;i<=n;++i)
			{
				if(a[i]==a[i-1]) ++sum;
				else c[++num]=sum,sum=1;
			}
			c[++num]=sum;n=num;c[n+1]=suf[n+1]=0;
			for(int i=1;i<=n;++i) pre[i]=pre[i-1]+c[i];
			for(int i=n;i>=1;--i) suf[i]=suf[i+1]+c[i];
			for(int l,r,i=1;i<=nn*2;i<<=1)
			{
				l=0,r=n+1;
				while(pre[l+1]<=i&&l<n) ++l;
				for(int j=1;j<=nn*2;j<<=1)
				{
					while(suf[r-1]<=j&&r>l+1) --r;
					ans=min(ans,i+j+up[pre[r-1]-pre[l]]-nn);
				}
			}
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
4
4
3 1 2 1
1
1
6
2 2 2 1 1 1
8
6 3 6 3 6 3 6 6

*/