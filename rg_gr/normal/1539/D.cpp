// Problem: D. PriceFixed
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define rg(x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}

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
int a[100005],b[100005],p[100005],ta[100005],tb[100005];
signed main()
{
	int n=read();
	rg(n)ta[i]=read(),tb[i]=read();p[i]=i;gr
	std::sort(p+1,p+1+n,[&](int x,int y){return tb[x]<tb[y];});
	rg(n)a[i]=ta[p[i]],b[i]=tb[p[i]];gr
	int l=1,r=n;
	int ans=0;
	int cc=0;
	while(1)
	{
		int i=l;
		b[i]-=cc;
		int f=1;
		while(b[i]>0)
		{
			if(r<l)
			{
				f=2;
				break;
			}
			if(b[i]>a[r])cc+=a[r],b[i]-=a[r],ans+=2*a[r],a[r]=0,r--;
			else 
			{
				cc+=b[i],a[r]-=b[i],ans+=2*b[i];if(a[r]==0)r--;
				break;
			}
		}
			
		ans+=a[l]*f;
		cc+=a[l];
		a[l]=0;
		l++;
		if(l>r||l==r&&a[l]==0)break;
	}
	oldl(ans);
	
	return 0;
}