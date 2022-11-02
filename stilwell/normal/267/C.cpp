#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

double cc[5005],g[105][105],g0[105],res[105],gtmp,Max,ans;
int gauss,gauss_num=2;
int n,n0,m,i,j,k;
int u[5005],v[5005],c[5005],id[105];
bool use[105];

void dfs(int x)
{
    if(use[x])return;
    use[x]=true;
    for(int i=1;i<=m;++i)
    {
        if(x==u[i])dfs(v[i]);
        if(x==v[i])dfs(u[i]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d",&u[i],&v[i],&c[i]);
    dfs(1);
    
    if(!use[n])
    {
        for(i=0;i<=m;++i)printf("0\n");
        return 0;
    }
    
    for(i=1;i<=n;++i)if(use[i])id[i]=++n0;
    n=n0;
    for(i=1;i<=m;++i)u[i]=id[u[i]],v[i]=id[v[i]];
    for(i=1;i<=m;++i)
    {
        g[u[i]][u[i]]+=1;g[u[i]][v[i]]-=1;
        g[v[i]][u[i]]-=1;g[v[i]][v[i]]+=1;
    }
    for(i=1;i<=n;++i)g0[i]=-g[i][1];
    for(i=2;i<n;++i)
    {
        int gauss=0;
        for(j=gauss_num;j<n;++j)
        if(((!gauss)&&(fabs(g[j][i])>1e-7))||(g[j][i]>g[gauss][i]))
        gauss=j;
        if(!gauss)for(;;);
        for(j=2;j<n;++j)swap(g[gauss_num][j],g[gauss][j]);
        swap(g0[gauss_num],g0[gauss]);
        for(j=gauss_num+1;j<n;++j)
        {
            gtmp=g[j][i]/g[gauss_num][i];
            for(k=i+1;k<n;++k)g[j][k]-=g[gauss_num][k]*gtmp;
            g0[j]-=gtmp*g0[i];
        }
        gauss_num++;
    }
    res[1]=1;
    for(i=gauss_num-1;i>=2;--i)
    {
        for(j=i+1;j<n;++j)g0[i]-=res[j]*g[i][j];
        if(fabs(g[i][i])>1e-7)res[i]=g0[i]/g[i][i];
    }
    Max=1e9;
    for(i=1;i<=m;++i)
    if(fabs(res[u[i]]-res[v[i]])>1e-7&&c[i]/fabs(res[u[i]]-res[v[i]])<Max)
    Max=c[i]/fabs(res[u[i]]-res[v[i]]);
    for(i=1;i<=m;++i)cc[i]=(res[u[i]]-res[v[i]])*Max;
    for(i=1;i<=m;++i)
    {
        if(u[i]==1)ans+=cc[i];
        if(v[i]==1)ans-=cc[i];
    }
    
    printf("%.10lf\n",ans);
    for(i=1;i<=m;++i)printf("%.10lf\n",cc[i]);
}