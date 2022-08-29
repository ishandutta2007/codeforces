#include<stdio.h>
#define MAXN 210000
using namespace std;
int sum;
int n;
long long ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int u;
            scanf("%d",&u);
            if(u==0)ans+=1ll*sum;
            sum+=u;
            }
    printf("%I64d\n",ans);
    return 0;
}