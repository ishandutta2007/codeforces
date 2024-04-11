#include<stdio.h>
#include<algorithm>
using namespace std;
long a[55];
long k,n;
bool cmp(long x,long y){return x>y;}
int main()
{
    scanf("%ld%ld",&n,&k);
    for(long i=1;i<=n;i++)scanf("%ld",&a[i]);
    sort(a+1,a+1+n,cmp);
    long i=0;long j=1;
    while(k--)
    {
              printf("%ld ",i+1);
              for(long s=1;s<=i;s++)printf("%ld ",a[s]);
              printf("%ld\n",a[j]);
              j++;if(j>n){i++;j=i+1;}
              }
    return 0;
}