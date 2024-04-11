// Problem: E. Longest Increasing Subsequence
// Contest: Codeforces - Codeforces Round #315 (Div. 1)
// URL: https://codeforces.com/problemset/problem/568/E
// Memory Limit: 128 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
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
typedef int arr[100005];
arr a,b,f,p,r,dp,v,ans;
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();a[++n]=0x3f3f3f3f;int m=read();
	for(int i=1;i<=m;i++)b[i]=read();std::sort(b+1,b+1+m);
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			int j=std::lower_bound(f+1,f+n+1,a[i])-f-1;
			p[i]=r[j],f[j+1]=a[i],r[j+1]=i,dp[i]=j+1;
		}
		else
		{
			int pos=i;
			for(int j=m;j;j--)
			{
				while(f[pos]>=b[j])pos--;
				f[pos+1]=b[j],r[pos+1]=i;
			}
		}
//		odb(dp[i]);
	}
	for(int i=dp[n]-1,qwq=a[n],qaq=n;~i;i--)
	{
		if(a[qaq]!=-1)
		{
			if(a[p[qaq]]!=-1)qwq=a[p[qaq]];
			else
			{
				int awa=std::lower_bound(b+1,b+m+1,a[qaq])-b-1;
				v[awa]=1;qwq=ans[p[qaq]]=b[awa];
			}
			qaq=p[qaq];
		}
		else
		{
			for(int j=qaq-1;j;j--)
			{
				if(a[j]!=-1&&a[j]<qwq&&dp[j]==i)
				{
					qwq=a[j];
					qaq=j;
					goto ng;
				}
			}
			for(int j=qaq-1;j;j--)
			{
				if(a[j]!=-1)continue;
				int awa=std::lower_bound(b+1,b+1+m,qwq)-b-1;
				v[awa]=1;qwq=ans[j]=b[awa];
				qaq=j;
				goto ng;
			}
			ng:;
		}
	}
	for(int i=1,j=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			if(ans[i])continue;
			while(v[j])j++;
			v[j]=1,ans[i]=b[j];
		}
		else ans[i]=a[i];
	}
	for(int i=1;i<n;i++)odb(ans[i]);
	return 0;
}