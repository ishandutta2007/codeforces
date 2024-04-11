// Problem: CF353D Queue
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF353D
// Memory Limit: 250 MB
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
	while(c!=EOF&&(c<'A'||c>'Z'))c=getchar();
	if(c==EOF)return c;
	return c=='M';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
signed main()
{
	int ans=0,c=0;
	while(1)
	{
		int x=re1d();
		if(x==-1)break;
		if(x)c++;
		else if(c)ans=max(ans+1,c);
	}
	printf("%d\n",ans);
}