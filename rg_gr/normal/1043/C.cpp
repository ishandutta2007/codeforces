// Problem: C. Smallest Word
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: http://codeforces.com/contest/1043/problem/C
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
char a[1005];
int r[1005];
void solve(int pos,int op)
{
	if(pos==0)return;
	if(op==1)
	{
		if(a[pos]==98)
		{
			solve(pos-1,1);
		}
		else
		{
			solve(pos-1,0);
			r[pos]=1;
		}
	}
	else
	{
		if(a[pos]==97)solve(pos-1,0);
		else
		{
			solve(pos-1,1);
			r[pos]=1;
		}
	}
}
signed main()
{
	scanf("%s",a);
	int n=strlen(a);
	solve(n-1,1);
	for(int i=0;i<n;i++)printf("%d ",r[i]);
}