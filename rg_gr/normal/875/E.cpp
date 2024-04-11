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
int a[200005];
signed main()
{
	int n=read(),s1=read(),s2=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=s1-s2<0?s2-s1:s1-s2,r=0x3f3f3f3f,ans=l;
	while(l<=r)
	{
		int m=l+r>>1;
		int L=-0x3f3f3f3f,R=0x3f3f3f3f;
		for(int i=n;i;i--)L<=a[i]&&a[i]<=R?(L=a[i]-m,R=a[i]+m):(L=max(L,a[i]-m),R=min(R,a[i]+m));
		(L<=s1&&s1<=R)||(L<=s2&&s2<=R)?(r=m-1,ans=m):l=m+1;
	}
	odl(ans);
	return 0;
}