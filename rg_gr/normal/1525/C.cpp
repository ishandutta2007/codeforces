// Problem: C. Robot Collisions
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	while(c<'A'||c>'Z')c=getchar();
	return c;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[2][300005],ans[300005];
int p[300005],c[300005];
int pp[300005],ccc[300005],f[300005];
int st[300005],cc,rr[300005];
int sz[2];
bool cmp(int a,int b)
{
	return pp[a]<pp[b];
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		memset(ans,-1,sizeof(ans));sz[0]=sz[1]=0;cc=0;
		for(int i=0;i<n;i++)pp[i]=read();
		for(int i=0;i<n;i++)ccc[i]=re1d(),f[i]=i;
		std::sort(f,f+n,cmp);
		for(int i=0;i<n;i++)p[i]=pp[f[i]],c[i]=ccc[f[i]],rr[f[i]]=i;
//		for(int i=0;i<n;i++)p[f[i]]=pp[i],c[f[i]]=ccc[i];
		for(int i=0;i<n;i++)a[p[i]&1][sz[p[i]&1]++]=i;
		cc=0;
		for(int i=0;i<sz[0];i++)
		{
			if(c[a[0][i]]=='R')st[cc++]=a[0][i];
			else
			{
				if(cc&&c[st[cc-1]]=='R')
				{
					int l=st[--cc],r=a[0][i];
					int res=(p[r]-p[l])>>1;
					ans[l]=ans[r]=res;
				}
				else st[cc++]=a[0][i];
			}
		}
		int res=cc;
		for(int i=0;i+1<cc;i+=2)
		{
			if(c[st[i]]=='L'&&c[st[i+1]]=='L')
			{
				int l=st[i],r=st[i+1];
				int aa=(p[r]+p[l])>>1;
				ans[l]=ans[r]=aa;
				res-=2;
			}
			else break;
		}
		for(int i=cc-1;i>0;i-=2)
		{
			if(c[st[i]]=='R'&&c[st[i-1]]=='R')
			{
				int l=st[i-1],r=st[i];
				int aa=(p[r]+p[l])>>1;
				ans[l]=ans[r]=m-aa;
				res-=2;
				cc-=2;
			}
			else break;
		}
		if(res==2)
		{
			int l=cc-2,r=l+1;
			l=st[l],r=st[r];
			int aa=(m+m-p[r]+p[l])>>1;
			ans[l]=ans[r]=aa;
		}
		
		
		
		cc=0;
		for(int i=0;i<sz[1];i++)
		{
			if(c[a[1][i]]=='R')st[cc++]=a[1][i];
			else
			{
				if(cc&&c[st[cc-1]]=='R')
				{
					int l=st[--cc],r=a[1][i];
					int res=(p[r]-p[l])>>1;
					ans[l]=ans[r]=res;
				}
				else st[cc++]=a[1][i];
			}
		}
		res=cc;
		for(int i=0;i+1<cc;i+=2)
		{
			if(c[st[i]]=='L'&&c[st[i+1]]=='L')
			{
				int l=st[i],r=st[i+1];
				int aa=(p[r]+p[l])>>1;
				ans[l]=ans[r]=aa;
				res-=2;
			}
			else break;
		}
		for(int i=cc-1;i>0;i-=2)
		{
			if(c[st[i]]=='R'&&c[st[i-1]]=='R')
			{
				int l=st[i-1],r=st[i];
				int aa=(p[r]+p[l])>>1;
				ans[l]=ans[r]=m-aa;
				res-=2;
				cc-=2;
			}
			else break;
		}
		if(res==2)
		{
			int l=cc-2,r=l+1;
			l=st[l],r=st[r];
			int aa=(m+m-p[r]+p[l])>>1;
			ans[l]=ans[r]=aa;
		}
		for(int i=0;i<n;i++)odb(ans[rr[i]]);
		puts("");
	}
	return 0;
}