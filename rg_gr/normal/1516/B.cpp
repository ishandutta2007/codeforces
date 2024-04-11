// Problem: B. AGAGA XOOORRR
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/B
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
int a[100005],pre[100005],suf[100005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();suf[n+1]=0;int x=0;
		for(int i=1;i<=n;i++)x^=a[i]=read();
		if(x==0)puts("YES");
		else
		{
			int cnt=0,p=0;
			for(int i=1;i<=n;i++)
			{
				cnt^=a[i];
				if(cnt==x)cnt=0,p++;
			}
			if(cnt||p<2)puts("NO");
			else puts("YES");
		}
		/*for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i],suf[n-i+1]=suf[n-i+2]^a[n-i+1];
		if(pre[n]==0){
		for(int i=2;i<=n;i++)if(pre[i-1]==suf[i])goto ng;
		puts("NO");
		continue;
		ng:;
		puts("YES");
		continue;
		}int x=0,p=-1;
		for(int i=1;i<=n;i++)
		{
			x^=a[i];
			if(x==pre[n])
			{
				p=i;
				break;
			}
		}
		if(p==-1)
		{
			puts("NO");
			continue;
		}
		for(int i=p+2;i<=n;i++)if((pre[i-1]^pre[p])==suf[i])goto nginx;
		puts("NO");
		continue;
		nginx:;
		puts("YES");
		continue;*/
	}
}