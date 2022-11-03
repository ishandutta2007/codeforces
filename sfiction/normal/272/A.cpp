/*
ID: Sfiction
OJ: CF
PROB: 272A
*/
#include <cstdio>
int main()
{
    int N,i,t,sum,ans;
    scanf("%d",&N);
    ++N;
    sum=0;
    for (i=1;i<N;++i)
    {
        scanf("%d",&t);
        sum+=t;
    }
    ans=0;
    for (i=1;i<6;++i) ans+=(sum+i)%N!=1;
    printf("%d",ans);
    return 0;
}