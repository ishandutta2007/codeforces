// Problem: B. TMT Document
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/B
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
char a[1000005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",a);
		int t=0,m=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='M')
			{
				m++;
				if(m>t)
				{
					puts("NO");
					goto ng;
				}
			}
			else t++;
		}
		t=0,m=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]=='M')
			{
				m++;
				if(m>t)
				{
					puts("NO");
					goto ng;
				}
			}
			else t++;
		}
		if(m*2==t)puts("YES");
		else puts("NO");
		ng:;
	}
}