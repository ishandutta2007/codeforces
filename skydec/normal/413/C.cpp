#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;
LL temp[105];LL now=0;LL a[105];
long n,m;
int main()
{
    scanf("%ld%ld",&n,&m);
    for(long i=1;i<=n;i++){scanf("%I64d",&a[i]);now+=a[i];}
    for(long i=1;i<=m;i++)
    {
             long v;scanf("%ld",&v);now-=a[v];
             temp[i]=a[v];
             }
    sort(temp+1,temp+1+m);
    for(long i=m;i>=1;i--)
    {
             now+=max(now,temp[i]);
             }
    printf("%I64d\n",now);
    return 0;
}