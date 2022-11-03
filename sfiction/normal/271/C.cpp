/*
ID: Sfiction
OJ: CF
PROB: 271C
*/
#include <cstdio>
int main()
{
    int N,K,M,T;
    int i,j;
    scanf("%d%d",&N,&K);
    if (3*K>N)
    {
        printf("-1");
        return 0;
    }
    printf("1");
    for (i=2;i<=K;++i) printf(" %d",i);
    M=N%K+1;
    T=N/K-1;
    for (i=1;i<M;++i)
        for (j=0;j<=T;++j) printf(" %d",i);
    for (;i<=K;++i)
        for (j=0;j<T;++j) printf(" %d",i);
    return 0;
}