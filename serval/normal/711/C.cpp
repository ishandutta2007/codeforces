#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k,i,j,x,y,c[105],cst[105][105];
long long f[2][105][105],ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d",&cst[i][j]);
    memset(f[0],0x3f,sizeof(f[0]));
    memset(f[0][0],0,sizeof(f[0][0]));
    for (i=1;i<=n;i++)
    {
        memset(f[i&1],0x3f,sizeof(f[i&1]));
        if (c[i]==0)
            for (j=1;j<=k;j++)
                for (x=1;x<=m;x++)
                    for (y=1;y<=m;y++)
                    {
                        if (x==y&&i!=1)
                            if (f[i&1^1][j][y]+cst[i][x]<f[i&1][j][x])
                                f[i&1][j][x]=f[i&1^1][j][y]+cst[i][x];
                        if (x!=y||i==1)
                            if (f[i&1^1][j-1][y]+cst[i][x]<f[i&1][j][x])
                                f[i&1][j][x]=f[i&1^1][j-1][y]+cst[i][x];
                    }
        if (c[i]!=0)
            for (j=1;j<=k;j++)
                for (y=1;y<=m;y++)
                {
                    if (c[i]==y&&i!=1)
                        if (f[i&1^1][j][y]<f[i&1][j][c[i]])
                            f[i&1][j][c[i]]=f[i&1^1][j][y];
                    if (c[i]!=y||i==1)
                        if (f[i&1^1][j-1][y]<f[i&1][j][c[i]])
                            f[i&1][j][c[i]]=f[i&1^1][j-1][y];
                }
    }
    ans=0x3f3f3f3f3f3f3f3f;
    for (i=1;i<=m;i++)
        if (f[n&1][k][i]<ans)
            ans=f[n&1][k][i];
    if (ans==0x3f3f3f3f3f3f3f3f)
        printf("-1\n");
    else
        printf("%I64d\n",ans);
    return 0;
}