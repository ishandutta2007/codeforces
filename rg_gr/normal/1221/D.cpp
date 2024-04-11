#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	//int num=0,f=1;char c=getchar();
	//while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	//while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int a[300005],b[300005],p[300005];
int dp[300005][3];
signed main()
{
int T=read();
while(T--)
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	int ans=0;a[0]=-54;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[i][j]=0x3f3f3f3f3f3f3f;
			for(int k=0;k<3;k++)
			{
				if(a[i-1]+k==a[i]+j)continue;
				dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
			}
		}
	}
	printf("%lld\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
	//int n=read();
	//for(int i=1;i<=n;i++)a[i]=re1d();
	/*int n=read();
	a[0]=-555,a[n+1]=-555;
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),p[i]=i;
	std::sort(p+1,p+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int pos=p[i];
		#define i pos
		while(a[i]==a[i-1]||a[i]==a[i+1])a[i]++,ans+=b[i];
		#undef i
	}
	printf("%lld\n",ans);*/
	//{
	//	if(i==0)d[0][a[i]]=0,d[0][a[0]+1]=b[i],d[0][a[0]+2]=b[i]*2;
	//	else
	//	{
	//		//if(d[i-1][a[i]])d[i][a[i]]=min(d[i][a[i]+1],d[i-1][a])
	//	}
		//qwq=min(d[i][a[i]],min(d[i][a[i]+1],d[i][a[i]+2]));
	//}
}
}
//1m1m4m5m1m4m 1p9p1p9p8p1p 5z