#include<stdio.h>
int n,m,i,j,sum;
int g[1005][1005];
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[b][a]=1;
        g[1][a]=g[n][a]=g[b][1]=g[b][n]=1;
    }
    g[1][1]=g[1][n]=g[n][1]=g[n][n]=0;
    for (i=2;i<n;i++) 
    {
            if (g[1][i]==0) sum++;
            if (g[i][1]==0) sum++;
    }
    if (n%2==1)
    {
        if (g[1][n/2+1]==0 && g[n/2+1][1]==0) sum--;
    }
    printf("%d\n",sum);
    return 0;
}