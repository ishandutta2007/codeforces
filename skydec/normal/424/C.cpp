#include<stdio.h>
using namespace std;
long xors[1100000];
long n;long q;
int main()
{
    scanf("%ld",&n);q=0;
    for(long i=1;i<=n;i++)
    {
        long v;scanf("%ld",&v);
        q^=v;
    }
    xors[0]=0;
    for(long i=1;i<=n;i++)xors[i]=xors[i-1]^i;
    for(long i=1;i<=n;i++)
    {
        long k=n/i;
        long mo=n%i;
        if(k&1)q^=xors[i-1];
        q^=xors[mo];
    }
    printf("%ld\n",q);
    return 0;
}