// Problem: D. 1-2-K Game
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define x m
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
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		if(n==0)puts("Bob");
//else 		if(n%m==0||(n%3))puts("Alice");
		//else if(n%3)puts("Alice");
		//else if(m%3)puts("Bob");
		//else if(n>=m&&n%(m+1)==m)puts("Alice");
		//else puts("Bob");
		else
		{
			if(m%3)
			{
				if(n%3)puts("Alice");
				else puts("Bob");
			}
			else
			{
				n%=(x+1);
				if(n%3||n==x)puts("Alice");
				else puts("Bob");
			}
		}
		
		//if()
	}
}