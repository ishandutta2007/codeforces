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
#define rg_(i,x) for(int i=1;i<=(x);i++){
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
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
{\
	int fx=f(x),fy=f(y);\
	if(fx==fy)return 0;\
	if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
	fa[fx]=fy,sz[fy]+=sz[fx];\
	return 1;\
}
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
int a[500005];
signed main()
{
	int n=read(),ans=0,*p=a,*q=a;
	double res=0;
	rg(n)int op=read();
	if(op==2)printf("%.7lf\n",res);
	else 
	{
		int x=read();
		res=*q-res;
		ans=ans-(p!=q)**q;
		ans=ans+(*(++q)=x);
//		odl(ans);
		res=(res*(p-a+1)-*(q-1)+*q)/(p-a+1);
		res=*q-res;
//		odb(ans);printf("%.7lf\n",res);
		while(*q-1.0*(ans+(p+1!=q)**(p+1))/((p-a)+1+(p+1!=q))>res)
		res=*q-1.0*(ans+(p+1!=q)**(p+1))/((p-a)+1+(p+1!=q))//,printf("?"),
		,++p,ans+=(p!=q)**p;
//		printf("%d %u %u %u %.7lf\n",ans,a,p,q,res);
	}gr
	//x=read()
	return 0;
}