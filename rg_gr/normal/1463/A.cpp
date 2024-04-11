// Problem: A. Dungeon
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1463/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
signed main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read();
		int qwq=min(a,min(b,c));
		if((a+b+c)%9)puts("NO");
		else if((a+b+c)/9>qwq)puts("NO");
		else puts("YES");
	}
}