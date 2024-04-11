/*
ID: Sfiction
OJ: CF128 Div2
PROB: A
*/
#include <stdio.h>
int main()
{
    int f[601]={1};
    int x,t,i,j,a,b,da,db,ta,tb;
    scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
    for (i=0;i<t;i++)
        for (j=0;j<t;j++)
        {
            ta=a-da*i;
            tb=b-db*j;
            if (ta<0) ta=0;
            if (tb<0) tb=0;
            f[ta+tb]=1;
            f[ta]=1;
            f[tb]=1;
        }
    if (f[x]) printf("YES");
    else printf("NO");
    return 0;
}