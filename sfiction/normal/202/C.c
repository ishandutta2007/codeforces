/*
ID: Sfiction
OJ: CF127 Div2
PROB: C
*/
#include <stdio.h>
int main()
{
    int s,n,x;
    scanf("%d",&x);
    if (x==3) n=5;
    else
        for (s=1,n=1;s<x;s=(n*n+1)/2) n+=2;
    printf("%d",n);
    return 0;
}