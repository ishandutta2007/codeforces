#include<stdio.h>
#define MAXN 2000000
#define jsb 1000000007
using namespace std;
int a[MAXN],f[MAXN],c[MAXN];
int n;
int tw[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&a[i]);
            f[a[i]]++;
            }
    int N=(1<<20);
    tw[0]=1;
    for(int i=1;i<=N;i++)tw[i]=tw[i-1]*2%jsb;
    for(int j=0;j<=19;j++)
    for(int i=0;i<=N;i++)
    if((i&(1<<j))>0)f[i-(1<<j)]+=f[i],c[i]++;
    int ans=0;
    for(int i=0;i<=N;i++)
    {
            int tmp=(tw[f[i]]-1+jsb)%jsb;
            if(c[i]&1)ans=(ans-tmp+jsb)%jsb;
            else ans=(ans+tmp)%jsb;
            }
    ans=(ans+jsb)%jsb;
    printf("%d\n",ans);
    return 0;
}