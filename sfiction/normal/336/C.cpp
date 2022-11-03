/*
ID: Sfiction
OJ: CF
PROB: 336C
*/
#include <cstdio>
#include <cstring>
const int MAXN=100000;
int a[MAXN];
char vis[MAXN];
int main()
{
    int n;
    int i,j;
    int s,t,g;
    scanf("%d",&n);
    for (i=0;i<n;++i) scanf("%d",&a[i]);
    for (i=29;i>=0;--i)
    {
        memset(vis,0,n);
        s=0;
        t=(1<<(i+1))-1;
        g=1<<i;
        for (j=0;j<n;++j)
            if (a[j]&g)
            {
                t&=a[j];
                vis[j]=1;
                ++s;
            }
        if (t%g==0) break;
    }
    printf("%d\n",s);
    for (i=0;i<n;++i)
        if (vis[i])
        {
            printf("%d",a[i]);
            --s;
            if (s) printf(" ");
        }
    return 0;
}