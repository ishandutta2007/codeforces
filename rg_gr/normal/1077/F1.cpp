// Problem: P3572 [POI2014]PTA-Little Bird
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3572
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <iostream>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define Keai --
#include <deque>
#define int long long
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
int a[205],h=0,t=0,f[205][205];
std::deque<int>q[205];
signed main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	q[0].push_back(0);
	for(int i=1;i<=n;i++)
		for(int j=k;j;j--)
		{
			while(q[j-1].size()&&q[j-1].front()<i-m)q[j-1].pop_front();
			if(!q[j-1].size())f[i][j]=-0x1145141919810;
			else 
			{
				f[i][j]=f[q[j-1].front()][j-1]+a[i];
				while(q[j].size()&&f[q[j].back()][j]<=f[i][j])q[j].pop_back();
				q[j].push_back(i);
			}
			
		}
	int ans=-1;
	for(int i=n-m+1;i<=n;i++)ans=max(ans,f[i][k]);
	oldl(ans);
	return 0;
}