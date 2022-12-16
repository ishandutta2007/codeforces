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
	const int N=110,inf=1e12+10;
	int n,m,sum,ret=1e12;
	int haku=8000;
	int f[N][N];
	int a[N];
	int dp[11][N];
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				f[i][j]=read();
			}
		}
		srand(19260817+n+m);
		while(haku--)
		{
       		for (int i=1;i<=n;++i)
            	a[i] = rand()&1;
        	for(int i=0;i<=m;++i)
        		for(int j=1;j<=n;++j)
        			dp[i][j]=inf;
        	dp[0][1]=0;
        	for(int t=0;t<m;++t)
        	{
        		for(int i=1;i<=n;++i)
        		{
        			if(dp[t][i]>=inf) continue;
        			for(int j=1;j<=n;++j)
        			{
        				if(a[i]==a[j]) continue;
        				dp[t+1][j]=min(dp[t+1][j],dp[t][i]+f[i][j]);
					}
				}
			}
			ret=min(ret,dp[m][1]);
    	}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}