/*
ID: Sfiction
OJ: CF
PROB: 272B
*/
#include <cstdio>
const int MAXS=30;
long long a[MAXS];
int main()
{
    int N,t,sum,i;
    long long ans;
    scanf("%d",&N);
    for (;N;--N)
    {
        scanf("%d",&t);
        for (sum=0;t;t>>=1) sum+=t&1;
        ++a[sum];
    }
    ans=0;
    for (i=1;i<MAXS;++i)
        if (a[i]) ans+=a[i]*(a[i]-1)/2;
    printf("%I64d",ans);
    return 0;
}