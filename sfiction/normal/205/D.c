/*
ID: Sfiction
OJ: CF129 Div2
PROB: D
*/
#include <stdio.h>
#include <stdlib.h>
int Comp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int a[100000][2],b[200000],ans[20][2];
    int i,j,N,M,t,times,max,min;
    scanf("%d",&N);
    for (M=i=0;i<N;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        b[M++]=a[i][0];
        if (a[i][0]!=a[i][1]) b[M++]=a[i][1];
    }
    qsort(b,M,sizeof(int),Comp);
    max=(N+1)/2;
    t=0;
    for (i=0;i<M;i=j)
    {
        for (j=i+1;j<M&&b[j]==b[i];j++);
        if (j-i>=max)
        {
            ans[t][0]=j-i;
            ans[t++][1]=b[i];
        }
    }
    if (t==0)
    {
        printf("-1");
        return 0;
    }
    qsort(ans,t,sizeof(int)*2,Comp);
    min=100000000;
    for (i=0;i<t;i++)
    {
        times=0;
        for (j=0;j<N;j++)
            if (ans[i][1]==a[j][0]) times++;
        if (min>max-times) min=max-times;
    }
    if (min<0) min=0;
    printf("%d",min);
    return 0;
}