#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[1000001],b[1000001];
int x[1000001];
long long ans,sum,sum1;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%I64d",&x[i]);
    sort(x+1,x+1+n);
    a[1]=0;
    sum=0;
    sum1=0;
    for (int i=2;i<=n;i++)
    {
        if((i-2)%m==0)
        {
            sum+=x[i-1];
            sum1++;
        }
        a[i]=(1ll*x[i]*sum1-sum)*2;
    }
    b[n]=0;
    sum=0;
    sum1=0;
    for(int i=n-1;i>=1;i--)
    {
        if ((n-i-1)%m==0)
        {
            sum+=x[i+1];
            sum1++;
        }
        b[i]=(sum-1ll*x[i]*sum1)*2;
    }
    ans=a[1]+b[1];
    for(int i=1;i<=n;i++)
        ans=min(ans,a[i]+b[i]);
    printf("%I64d",ans);
}