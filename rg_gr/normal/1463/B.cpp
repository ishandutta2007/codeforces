// Problem: B. Find The Array
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1463/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[55],b[55];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),S=0,del=0;
		for(int i=0;i<n;i++)
		{
			S+=a[i]=read();int x=a[i];
			if(i&1)b[i]=1;
			else b[i]=a[i];
			if(b[i]>a[i])del+=b[i]-a[i];
			else del+=a[i]-b[i];
		}
		if(del*2<=S)
		{
			for(int i=0;i<n;i++)printf("%lld ",b[i]);
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				int x=a[i];
				if((i^1)&1)b[i]=1;
				else b[i]=x;
				if(b[i]>a[i])del+=b[i]-a[i];
				else del+=a[i]-b[i];
			}
			for(int i=0;i<n;i++)printf("%lld ",b[i]);
		}
		puts("");
	}
}