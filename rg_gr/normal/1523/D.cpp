// Problem: D. Love-Hate
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <bitset>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
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
long long a[200005];
int cnt[64],p[64];
inline int kuaikule(int a,int b){return cnt[a-1]==cnt[b-1]?a<b:cnt[a-1]>cnt[b-1];}
signed main()
{
	srand((115415));
	int n=read(),m=read(),pp=read(),lim=(n+1)/2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			long long x=re1d();
			cnt[j]+=x;
			a[i]|=(x<<j);
		}
	}
	for(int i=1;i<=m;i++)p[i]=i;
	std::sort(p+1,p+1+m,kuaikule);
	int res=0,ccc=0;
//	n=200000;lim=100000;
int qd=m;
m=min(m,pp+pp);
	for(int i=0;i<=363;i++)
	{
		int cc=0;
		for(int i=1;i<=m;i++)
		{
			cc+=(1ll<<p[i]-1);
			if(cnt[p[i]-1]<lim)cc-=(1ll<<p[i]-1);
			else
			{
				int yy=0;
				for(int i=0;i<n;i++)
				{
					if((a[i]&cc)==cc)yy++;
				}
				if(yy<lim)cc-=(1ll<<p[i]-1);
			}
		}
		int pl=__builtin_popcountll(cc);
		if(pl>ccc)
		{
			res=cc;
			ccc=pl;
		}
		std::random_shuffle(p+1,p+m+1);
	}
	for(int i=0;i<qd;i++,res>>=1)old(res&1);
	return 0;
}