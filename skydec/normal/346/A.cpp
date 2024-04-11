#include<stdio.h>
using namespace std;
long n,gcd;
long GCD(long a,long b)
{
     if(!a||!b)return a+b;
     return GCD(b,a%b);
}
int main()
{
    scanf("%ld",&n);gcd=0;long max=0;
    for(long i=1;i<=n;i++)
    {
             long a;scanf("%ld",&a);
             gcd=GCD(gcd,a);
             if(a>max)max=a;
             }
    if(((max/gcd)-n)%2==0)printf("Bob");
    else printf("Alice");
    return 0;
}