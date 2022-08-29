#include<stdio.h>
using namespace std;
typedef long long LL;
int n;LL ans=0;
bool use[1100000];
int a[35];
int work(int x)
{
    int u=x;
    for(int i=0;i<=31;i++)a[i]=(u%2==0),u/=2;
    int p=0;int t=1;int i=0;
    for(i=0;i<=31;i++)
    {
            if(p+t*a[i]>n)break;
            p+=t*a[i];t*=2;a[i]=p;
            }
    i--;
    while(use[a[i]]&&i>=1)i--;
    if(use[a[i]]==1)p=0;
    else p=a[i],use[a[i]]=1;
    return p;
}
int res[1100000];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){res[i]=work(i);ans+=1ll*(i^res[i]);}
    int u=0;
    while(use[u])u++;ans+=1ll*u;res[0]=u;
    printf("%I64d\n",ans);
    for(int i=0;i<=n;i++)printf("%d ",res[i]);
    return 0;
}