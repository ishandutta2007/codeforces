// Problem: C. Compression and Expansion
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1005],cc;
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();cc=0;
		for(int i=0;i<n;i++)
		{
			int x=read();
			if(x==1)a[++cc]=1;
			else if(a[cc]+1==x)
			{
				a[cc]++;
			}
			else
			{
				do cc--; while(a[cc]+1!=x);
				a[cc]++;
			}
			for(int i=1;i<=cc;i++)
			{
				if(i==cc)printf("%d\n",a[i]);
				else printf("%d.",a[i]);
			}
		}
/*		memset(h,0,sizeof(h));
		memset(cur,0,sizeof(h));
		memset(nxt,0,sizeof(h));
		memset(data,0,sizeof(data));
		int cc=1;
		int n=read();
		for(int i=1;i<=n;i++)
		{
			int x=read();
			if(x==1)
			{
				for(int j=0;;j++)
				{
					if(data[i-1][j]==0)
					{
						data[i][j]=1;
						break;
					}
					data[i][j]=data[i-1][j];
				}
				if(h[1]==0)h[1]=cur[1]=i;
				else nxt[h[1]]=i,h[1]=i;
			}
			else
			{
				int k=cur[x-1];
				cur[x-1]=nxt[cur[x-1]];
				for(int j=0;;j++)
				{
					if(data[k][j]==0)
					{
						data[i][j-1]+=1;
						break;
					}
					data[i][j]=data[k][j];
				}
				if(h[x]==0)h[x]=cur[x]=i;
				else nxt[h[x]]=i,h[x]=i;
			}
			for(int j=0;;j++)
			{
				printf("%d",data[i][j]);
				if(data[i][j+1])
				{
					putchar('.');
				}
				else
				{
					puts("");
					break;
				}
			}
		}*/
	}
	return 0;
}