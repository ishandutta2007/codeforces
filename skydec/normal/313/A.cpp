#include<stdio.h>
using namespace std;
long n;
int main()
{
    scanf("%ld",&n);
    long a,b;
    a=n/10;
    b=(n/100)*10+(n%10);
    if(a>n)n=a;
    if(b>n)n=b;
    printf("%ld\n",n);
    return 0;
}