// Problem: E. Almost Sorted
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/E
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
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[1000005],ans[1000005];
const int inf=0x3f3f3f3f3f3f3f3fll;
signed main()
{
	//printf("%lld\n",inf-1000000000000000000ll);
	//return 0;
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		a[0]=a[1]=1;
		for(int i=2;i<=n;i++)a[i]=min(2*a[i-1],inf);
		int cnt=0;
		if(m>a[n])
		{
			puts("-1");
			goto ng;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;;j++)
			{
				if(m>a[n-i-j])m-=a[n-i-j];
				else
				{
					i+=j;
					for(int k=0;k<=j;k++)ans[cnt++]=i-k;
					break;
				}
			}
		}
		for(int i=0;i<cnt;i++)printf("%lld ",ans[i]);
		puts("");
		ng:;
	}
}