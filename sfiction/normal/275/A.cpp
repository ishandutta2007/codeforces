/*
ID: Sfiction
OJ: TC
PROB: 275A
*/
#include <cstdio>
int a[5][5];
int main()
{
    int i,j,t;
    for (i=1;i<=3;++i)
        for (j=1;j<=3;++j)
        {
            scanf("%d",&t);
            a[i][j]+=t;
            a[i-1][j]+=t;
            a[i+1][j]+=t;
            a[i][j-1]+=t;
            a[i][j+1]+=t;
        }
    for (i=1;i<=3;++i) printf("%d",(a[1][i]+1)%2);
    printf("\n");
    for (i=1;i<=3;++i) printf("%d",(a[2][i]+1)%2);
    printf("\n");
    for (i=1;i<=3;++i) printf("%d",(a[3][i]+1)%2);
    return 0;
}