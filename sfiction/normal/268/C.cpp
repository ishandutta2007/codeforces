/*
ID: Sfiction
OJ: CF
PROB: 268C
*/
/*

sum=min{m,n}+1
x+y=m
sqrt(2)
*/
#include <cstdio>
int main()
{
    int N,M,i;
    scanf("%d%d",&N,&M);
    if (N<M) printf("%d",N+1);
    else printf("%d",M+1);
    for (i=0;M>=0&&i<=N;++i,--M) printf("\n%d %d",i,M);
    return 0;
}