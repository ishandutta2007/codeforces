#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
    int u,v,w;
    bool operator<(const Edge& b)
    {
        return w<b.w;
    }
}e[8000005];
int sz[4005],fa[4005];
int f(int x)
{
    return x==fa[x]?x:fa[x]=f(fa[x]);
}
int u(int x,int y)
{
    int fx=f(x),fy=f(y);
    if(fx==fy)return 0;
    if(sz[fx]>sz[fy])fy^=fx^=fy^=fx;
    sz[fy]+=sz[fx],fa[fx]=fy;
    return 1;
}
int x[2005],y[2005],c[2005],k[2005];
int C[2005],cc;
int X[2005],Y[2005],xy;
int abcd(int a){return a>0?a:-a;}
signed main()
{
    int n=read(),cnt=0;
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    for(int i=1;i<=n;i++)c[i]=read();
    for(int i=1;i<=n;i++)k[i]=read();
    for(int i=1;i<=n;i++)e[cnt++]={0,i,c[i]};
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;sz[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)e[cnt++]=(Edge){i,j,(k[i]+k[j])*(abcd(x[i]-x[j])+abcd(y[i]-y[j]))};
    std::sort(e,e+cnt);
    int y=0,q=0;
    for(int i=0;i<cnt;i++)
    {
        int uu=e[i].u,v=e[i].v,w=e[i].w;
        if(u(uu,v))
        {
            if(uu<v)uu^=v^=uu^=v;
            if(v==0)C[cc++]=uu;
            else X[xy]=uu,Y[xy++]=v;
            y++,q+=w;
        }
        if(y==n)break;
    }
    printf("%lld\n%lld\n",q,cc);
    for(int i=0;i<cc;i++)printf("%lld ",C[i]);
    printf("\n%lld\n",xy);
    for(int i=0;i<xy;i++)printf("%lld %lld\n",X[i],Y[i]);
}
//425316