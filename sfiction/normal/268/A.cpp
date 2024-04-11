/*
ID: Sfiction
OJ: CF
PROB: 268A
*/
/*
O(N^2)iO(N)
*/
#include <cstdio>
const int MAXN=30,MAXM=100;
int host[MAXM+1],guest[MAXN];
int main()
{
    int N;
    int i,temp,sum;
    scanf("%d",&N);
    for (i=0;i<N;++i)
    {
        scanf("%d%d",&temp,&guest[i]);
        ++host[temp];
    }
    sum=0;
    for (i=0;i<N;++i) sum+=host[guest[i]];
    printf("%d",sum);
    return 0;
}