#include<stdio.h>
using namespace std;
long sum=0;
long n;
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             long a;scanf("%ld",&a);sum+=a;
             }
    if(sum%n==0)printf("%ld\n",n);else printf("%ld\n",n-1);
    return 0;
}