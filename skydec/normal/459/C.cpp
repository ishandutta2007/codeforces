#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long LL;
int n,k,d;
int tt[1005];
int main()
{
    scanf("%d%d%d",&n,&k,&d);
    LL u=k;int pp=1;
    if(k==1)
    {
            if(n!=1)
            {
                    printf("-1\n");
                    return 0;
                    }
                    }
    else
    {
    while(u<n)u*=1ll*k,pp++;
    if(pp>d)
    {
            printf("-1\n");
            return 0;
            }
            }
    for(int i=1;i<=n;i++)tt[i]=i;
    for(int i=1;i<=d;i++)
    {
            for(int j=1;j<=n;j++)printf("%d ",tt[j]%k+1),tt[j]/=k;
            printf("\n");
            }
    return 0;
}