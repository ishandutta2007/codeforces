#include<stdio.h>
#include<algorithm>
#define MAXN 510000
using namespace std;
long n;long a[MAXN];
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)scanf("%ld",&a[i]);
    sort(a+1,a+1+n);long i=1;long j=n/2+1;
    while(j<=n&&i<=n/2)
    {
        while(j<=n&&a[j]<a[i]*2)j++;
        if(j>n)break;
        j++;i++;
    }
    printf("%ld\n",n-i+1);
    return 0;
}