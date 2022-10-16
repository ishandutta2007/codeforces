// Problem: C. From S To T
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/C
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
char a[1005],b[1005],c[1005];
int t[1005];
signed main()
{
	int Q=read();
	while(Q--)
	{
		scanf("%s%s%s",a,b,c);
		int cl=0,cr=0;
		int la=strlen(a),lb=strlen(b);
		int lc=strlen(c);
		while(cr<la)
		{
			if(cl>=lb)goto ng;
			while(b[cl]!=a[cr])
			{
				cl++;
				if(cl>=lb)goto ng;
			}
			cl++;cr++;
		}
		memset(t,0,sizeof(int)*128);
		for(int i=0;i<la;i++)t[a[i]]++;
		for(int i=0;i<lb;i++)t[b[i]]--;
		for(int i=0;i<lc;i++)t[c[i]]++;
		for(int i='a';i<='z';i++)
		{
			if(t[i]<0)goto ng;
		}
		puts("YES");
		continue;
		ng:;
		puts("NO");
	}
}