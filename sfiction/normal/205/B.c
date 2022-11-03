/*
ID: Sfiction
OJ: CF129 Div2
PROB: B
*/
#include <stdio.h>
#include <string.h>
int main()
{
    long long sum,u,v;
    int i,N;
    sum=0;
    scanf("%d",&N);
    scanf("%I64d",&u);
    for (i=1;i<N;i++)
    {
        scanf("%I64d",&v);
        if (u>v) sum+=u-v;
        u=v;
    }
    printf("%I64d",sum);
    return 0;
}