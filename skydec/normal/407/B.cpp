#include<stdio.h>
#include<cstring>
#define jsb 1000000007
#define MAXN 1005
using namespace std;
int f[MAXN];
int p[MAXN];
int n;
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
    {
            f[i]=1;
            for(int j=p[i];j<i;j++)
            f[i]=(f[i]+f[j]+1)%jsb;
            ans=(ans+f[i]+1)%jsb;
            }
    printf("%d\n",ans);
    return 0;
}