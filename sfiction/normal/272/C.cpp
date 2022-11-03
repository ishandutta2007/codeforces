/*
ID: Sfiction
OJ: CF
PROB: 272C
*/
#include <cstdio>
const int MAXN=100000;
long long stair[MAXN+1];
int main()
{
    int N,M,i;
    long long width,height;
    long long pre,now;
    scanf("%d",&N);
    for (i=1;i<=N;++i) scanf("%I64d",&stair[i]);
    scanf("%d",&M);
    for (pre=0;M;--M)
    {
        scanf("%I64d%I64d",&width,&height);
        if (stair[width]>pre) now=stair[width];
        else now=pre;
        pre=now+height;
        printf("%I64d",now);
        if (M>1) printf("\n");
    }
    return 0;
}