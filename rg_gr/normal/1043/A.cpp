// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: http://codeforces.com/contest/1043/problem/A
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
int a[2005];
signed main()
{
	int n=read(),sum=0;
	for(int i=0;i<n;i++)sum+=a[i]=read();
	//printf("%d\n",max((sum*2)/n+1,n));
	int ans=0;
	for(int i=0;i<1000;i++)
	{
		int qwq=0;
		for(int j=0;j<n;j++)
		{
			int qaq=i-a[j];
			if(qaq<0)goto ng;
			qwq+=qaq;
		}
		if(qwq>sum){printf("%d\n",i);return 0;}
		ng:;
	}
}