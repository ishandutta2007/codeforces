// Problem: D. Cut
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int pre[200005],a[200005],Max[20][100005];
#define f Max[0]
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];int t=a[i];
		for(int j=2;j*j<=a[i];j++)
		{
			if(a[i]%j)continue;
			f[i]=max(f[i],pre[j]);
			pre[j]=i;
			while(t%j==0)t/=j;
		}
		if(t>1)
		{
			f[i]=max(f[i],pre[t]);
			pre[t]=i;
		}
//		printf("%d ",f[i]);
	}
	for(int j=1;j<=18;j++)
		for(int i=(1<<j);i<=n;i++)Max[j][i]=Max[j-1][Max[j-1][i]];
	while(m--)
	{
		int l=read(),r=read(),ans=1;
		for(int i=18;i>=0;i--)if(Max[i][r]>=l)ans+=(1<<i),r=Max[i][r];
		printf("%d\n",ans);
	}
}