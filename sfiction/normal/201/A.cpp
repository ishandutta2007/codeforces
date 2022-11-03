/*
ID: Sfiction
OJ: CF
PROB: 201A
*/
/*
N
N
N1(N*N+1)/2
N1..(N*N+1)/21
1.
2.
3.12
4.
(N*N+1)/2x
N
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