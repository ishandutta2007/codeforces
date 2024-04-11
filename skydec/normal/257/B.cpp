#include<stdio.h>
using namespace std;
long n,m;
int main()
{
    scanf("%ld%ld",&n,&m);
    if(n<m)
    {
           long t=n;n=m;m=t;
           }
    printf("%ld %ld\n",n-1,m);
    return 0;
}