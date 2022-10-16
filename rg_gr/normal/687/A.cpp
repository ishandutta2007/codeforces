#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#define int long long
inline long long read()
{
	long long num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
    int v,nxt;
}e[500005];
int h[200005],cnt=1;
inline void addedge(int u,int v)
{
    e[cnt]=(Edge){v,h[u]};
    h[u]=cnt++;
}
int C[200005],S[4];
inline void col(int u,int c)
{
    C[u]=c,S[c]++;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(C[v])if(C[v]==c){puts("-1");exit(0);}else;
        else col(v,3^c);
    }
}
signed main()
{
    int n=read(),m=read();
    for(int i=0;i<m;i++)
    {
        int x=read(),y=read();
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=1;i<=n;i++)if(!C[i])col(i,1);
    printf("%lld\n",S[1]);
    for(int i=1;i<=n;i++)if(C[i]==1)printf("%lld ",i);puts("");
    printf("%lld\n",S[2]);
    for(int i=1;i<=n;i++)if(C[i]==2)printf("%lld ",i);puts("");
	return 0;
}