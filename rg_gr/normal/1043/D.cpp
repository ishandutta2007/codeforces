// Problem: D. Mysterious Crime
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: http://codeforces.com/contest/1043/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
int a[10][200005],pos[10],qwq[10][200001];
signed main()
{
	int n=read(),m=read();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)a[i][j]=read(),qwq[i][a[i][j]]=j;
	for(int i=0;i<m;i++)pos[i]=-500;
	long long l=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			l=1;
			continue;
		}
		int f=1;
		for(int j=1;j<m;j++)
		{
			if(qwq[j][a[0][i]]==qwq[j][a[0][i-1]]+1);
			else f=0;
		}
		if(f==0)
		{
//			for(int i=0;i<m;i++)pos[i]=-500;
			ans+=l*(l+1)>>1;
			l=0;
		}
		l++;
	}
	ans+=l*(l+1)>>1;
	printf("%lld\n",ans);
}