#include<cstdio>
double a[1025][1025];
int main()
{
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    if(m==1){printf("%d\n",(n-x)*2);return 0;}
    for(int i=n-1;i>=x;i--)
        for(int T=0;T<60;T++)
            for(int j=1;j<=m;j++)
                if(j==1)a[i][j]=(a[i+1][j]+a[i][j+1]+a[i][j])/3+1;else
                if(j==m)a[i][j]=(a[i+1][j]+a[i][j-1]+a[i][j])/3+1;else
                    a[i][j]=(a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i][j])/4+1;
    printf("%.9lf\n",a[x][y]);
    return 0;
}