// Problem: E. Gold Transfer
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/E
// Memory Limit: 256 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
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
#define rg(x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
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
typedef int arr[300005];
arr d,a,c,h;
int f[300005][21];
/*struct Edge{
	int v,nxt;
}e[300005];
int cnt=1;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}*/
signed main()
{
	int m=read();a[1]=read(),c[1]=read();
	for(int i=2;i<=m+1;i++)
	{
		int op=read();
		if(op==1)
		{
			f[i][0]=read()+1;
			a[i]=read();
			c[i]=read();
			for(int j=1;j<20;j++)f[i][j]=f[f[i][j-1]][j-1];
		}
		else
		{
			int v=read()+1,w=read();
			int cost=0,buy=0;
			while(w)
			{
				int u=v;
				if(a[f[u][0]]==0)
				{
					int t=min(a[u],w);
					buy+=t;
					cost+=t*c[u];
					a[u]-=t;
					break;
				}
				for(int i=19;i>=0;i--)
				{
					if(f[u][i]==0)continue;
					if(a[f[u][i]]==0)continue;
					u=f[u][i];
				}
				{
					int t=min(a[u],w);
					buy+=t;
					cost+=t*c[u];
					a[u]-=t;
					w-=t;
				}
			}
			oldp(buy,cost);
			fflush(stdout);
		}
	}
	return 0;
}