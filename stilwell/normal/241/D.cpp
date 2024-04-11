#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,t,p,i,j,k,u,v;
int a[100005],b[105],c[105],d[100005];
int from[32][32][50005];
bool ans[50005],trans[32][32][50005];

int main()
{
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;++i)scanf("%d",&a[i]),d[a[i]]=i;
    for(i=0;i<32;++i)
    for(j=0;j<p;++j)
    from[0][i][j]=-2;
    for(i=1;i<=n;++i)
    if(a[i]<32)
    {
        ++t;b[t]=i;c[t]=a[i];
        memcpy(from[t],from[t-1],sizeof(from[t]));
        for(v=1;v<=a[i];v*=10);
        from[t][a[i]][a[i]%p]=-1;
        trans[t][a[i]][a[i]%p]=true;
        for(j=0;j<32;++j)
        for(k=0;k<p;++k)
        if(from[t-1][j][k]!=-2)
        from[t][j^a[i]][(k*v+a[i])%p]=k,
        trans[t][j^a[i]][(k*v+a[i])%p]=true;
    }
    if(from[t][0][0]!=-2)
    {
        printf("Yes\n");
        u=v=m=0;
        for(i=t;i>=1;--i)
        if(trans[i][u][v])
        {
            ++m;ans[b[i]]=true;
            v=from[i][u][v];u^=c[i];
            if(v==-1)break;
        }
        printf("%d\n",m);
        for(i=1;i<=n;++i)if(ans[i])printf("%d ",i);
        printf("\n");
    }
    else printf("No\n");
}