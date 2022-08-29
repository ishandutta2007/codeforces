//by skydec
#include<stdio.h>
#include<cstdlib> 
using namespace std;
long a,b,n;
int main()
{
    scanf("%ld%ld%ld",&a,&b,&n);
    long q=a;q%=b; 
    for(long i=0;i<=9;i++)
    if((q*10+i)%b==0)
    {
                     printf("%ld%ld",a,i);
                     for(long j=2;j<=n;j++)printf("0");
                     return 0;
                     }
    printf("-1");
    return 0;
}