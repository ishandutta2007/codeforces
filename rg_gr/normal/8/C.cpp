// Problem: C. Looking for Order
// Contest: Codeforces - Codeforces Beta Round #8
// URL: https://codeforces.com/contest/8/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
//#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int X[30],Y[30],dis[30][30],dp[1<<24],pre[1<<24];
inline int highbit(unsigned x)
{
	int q=__builtin_clz(x);
	return 32-q;
}
signed main()
{
	X[0]=read(),Y[0]=read();
	int n=read();
	for(int i=1;i<=n;i++)X[i]=read(),Y[i]=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int T=1;T<(1u<<n);T++)
	{
		int i=highbit(T),k=T;
		while(k)
		{
			int j=highbit(k);
			k^=(1u<<(j-1));
			if(dp[T]>dp[T^((1u<<i-1)|(1u<<j-1))]+dis[0][i]+dis[i][j]+dis[j][0])
			{
				dp[T]=dp[T^((1u<<i-1)|(1u<<j-1))]+dis[0][i]+dis[i][j]+dis[j][0];
				pre[T]=T^((1u<<i-1)|(1u<<j-1));
			}
		}
	}
	printf("%d\n",dp[(1u<<n)-1]);
	int q=(1u<<n)-1;
	while(q)
	{
		printf("0 ");
		int p=q^pre[q];
		int w=(p&-p);
		p-=w;
		printf("%d ",highbit(w));
		if(p)printf("%d ",highbit(p));
		q=pre[q];
	}
	puts("0");
}