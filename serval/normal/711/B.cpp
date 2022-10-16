#include <cstdio>
using namespace std;
int n,i,j,x,y,px;
long long mg[505][505];
long long tx,sx,qx;
int main()
{
    scanf("%d",&n);
    if (n==1)
    {
        printf("1\n");
        return 0;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            scanf("%I64d",&mg[i][j]);
            if (mg[i][j]==0)
            {
                x=i;
                y=j;
            }
        }
    if (x==1)
        px=2;
    else
        px=1;
    for (i=1;i<=n;i++)
    {
        tx=tx+mg[px][i]-mg[x][i];
        sx+=mg[px][i];
    }
    mg[x][y]=tx;
    for (i=1;i<=n;i++)
    {
        qx=0;
        for (j=1;j<=n;j++)
            qx+=mg[i][j];
        if (qx!=sx)
        {
            printf("-1\n");
            return 0;
        }
        qx=0;
        for (j=1;j<=n;j++)
            qx+=mg[j][i];
        if (qx!=sx)
        {
            printf("-1\n");
            return 0;
        }
    }
    qx=0;
    for (i=1;i<=n;i++)
        qx+=mg[i][i];
    if (qx!=sx)
    {
        printf("-1\n");
        return 0;
    }
    qx=0;
    for (i=1;i<=n;i++)
        qx+=mg[i][n-i+1];
    if (qx!=sx)
    {
        printf("-1\n");
        return 0;
    }
    if (tx<=0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%I64d\n",tx);
    return 0;
}