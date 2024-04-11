// Problem: C. Baby Ehab Partitions Again
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <bitset>
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
int a[10005];
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
signed main()
{
	int n=read(),g=0,sum=0;std::bitset<200005> b;
	b=1;
	for(int i=1;i<=n;i++)sum+=a[i]=read(),b=(b|(b<<a[i])),g=gcd(g,a[i]);
	if(b[sum>>1]==0||(sum&1))puts("0");
	else
	{
		for(int i=1;i<=n;i++)
		{
			if((a[i]/g)&1)
			{
				printf("1\n%d\n",i);
				return 0;
			}
		}
	}
}