// Problem: B. Game with Telephone Numbers
// Contest: Codeforces - Educational Codeforces Round 63 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1155/problem/B
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
	while(c<48||c>57)c=getchar();
	return c^48;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[1000005];
signed main()
{
	int n=read();
	for(int i=0;i<n;i++)a[i]=re1d();
	int dell,delr=dell=(n-11)>>1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==8&&dell)a[i]=114514,dell--;
	}
	int f=-1;
	for(int i=0;i<n;i++)if(a[i]==8){f=i;break;}
	if(f==-1)return puts("NO")&0;
	for(int i=0;i<f;i++)if(a[i]!=114514)delr--;
	if(delr<0)puts("NO");
	else puts("YES");
}