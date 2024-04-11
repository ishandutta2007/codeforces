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
	int T,n;
	int t[N],h[N];
	int dp[N][2];
	bool vis[N];
	inline int calc(int l,int r)
	{
		return (l+r)*(r-l+1)/2;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i) t[i]=read(),vis[i]=0;
			for(int i=1;i<=n;++i) h[i]=read();
			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
					if(t[j]-t[i]<h[j]-h[i]) vis[i]=1;
				}
			}
			for(int i=1;i<=n;++i)
			{
				dp[i][0]=dp[i][1]=1e18;
				if(vis[i]) continue;
				int tmp=t[i]-h[i]+1,pos=i,qaq=0;
				for(int j=i;j;--j)
				{
					if(t[j]>=tmp) pos=j;
				}
				for(int j=pos;j<=i;++j)
				{
					if(t[j]-tmp+1<h[j]) qaq=1;
				}
				if(!qaq) dp[i][0]=min(dp[pos-1][0],dp[pos-1][1])+calc(1,h[i]);
				for(int j=1;j<i;++j)
				{
					dp[i][1]=min(dp[i][1],dp[j][0]+calc(h[j]+1,h[j]+(t[i]-t[j])));
				}
			//	cout<<dp[i][0]<<' '<<dp[i][1]<<"!!"<<endl;
			}
			printf("%lld\n",min(dp[n][0],dp[n][1]));
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
3
5 7 9
2 1 2

*/