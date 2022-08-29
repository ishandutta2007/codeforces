#include<stdio.h>
#include<algorithm>
using namespace std;
long n,m,k;
long a[55];
bool cmp(long x,long y){return x>y;}
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)scanf("%ld",&a[i]);
    sort(a+1,a+1+n,cmp);
    for(long p=0;p<=n;p++)
    {
             long sum=0;
             for(long j=1;j<=p;j++)sum+=a[j];
             if(sum+k-p>=m)
             {
                          printf("%ld\n",p);
                          return 0;
                          }
                          }
    printf("-1");
    return 0;
}