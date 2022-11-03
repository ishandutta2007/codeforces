/*
ID: Sfiction
OJ: CF128 Div2
PROB: B
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char f[1002][1002]={0},d[9]={-1,-1,-1,0,0,0,1,1,1},e[9]={-1,0,1,-1,0,1,-1,0,1};
    int x,y,i,j,N,M;
    scanf("%d%d",&N,&M);
    for (i=0;i<M;i++)
    {
        scanf("%d%d",&x,&y);
        for (j=0;j<9;j++)
        {
            if (f[x+d[j]][y+e[j]]==8)
            {
                printf("%d",i+1);
                return 0;
            }
            f[x+d[j]][y+e[j]]++;
        }
    }
    printf("-1");
    return 0;
}