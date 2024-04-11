#include<cstdio>
int n;bool a[55][55],b[55][55];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n*(n-1)/2-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=b[x][y]=b[y][x]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][k]&&a[k][j])a[i][j]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&a[i][j]&&!b[i][j])
            {
                printf("%d %d\n",i,j);
                return 0;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&!b[i][j])
            {
                printf("%d %d\n",i,j);
                return 0;
            }
    return 0;
}