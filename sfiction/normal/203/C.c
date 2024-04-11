/*
ID: Sfiction
OJ: CF128 Div2
PROB: C
*/
#include <stdio.h>
#include <stdlib.h>
int Comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int C[100000][2];
    int i,N,D,a,b,x,y;
    scanf("%d%d%d%d",&N,&D,&a,&b);
    for (i=0;i<N;i++)
    {
        scanf("%d%d",&x,&y);
        C[i][0]=a*x+b*y;
        C[i][1]=i+1;
    }
    qsort(C,N,sizeof(int)*2,Comp);
    for (i=0;i<N&&D>=C[i][0];i++) D-=C[i][0];
    printf("%d\n",i);
    if (i>0)
    {
        i--;
        printf("%d",C[i][1]);
        for (i--;i>=0;i--) printf(" %d",C[i][1]);
    }
    return 0;
}