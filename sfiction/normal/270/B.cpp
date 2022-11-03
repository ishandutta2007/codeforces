/*
ID: Sfiction
OJ: CF
PROB: 270B
*/
#include <cstdio>
const int MAXN=100000;
int a[MAXN];
int main()
{
    int N;
    int i,pre,now,ans;
    scanf("%d",&N);
    ans=pre=0;
    for (i=0;i<N;++i)
    {
        scanf("%d",&now);
        if (pre>now) ans=i;
        pre=now;
    }
    printf("%d",ans);
    return 0;
}