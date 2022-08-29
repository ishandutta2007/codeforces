#include<stdio.h>
using namespace std;
long min=2100000000;
long n;long k[200];
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)scanf("%ld",&k[i]);
    for(long i=1;i<=n;i++)
    {
             long sp=k[i]*15;
             for(long j=1;j<=k[i];j++)
             {
                      long u;scanf("%ld",&u);sp+=u*5;
                      }
             if(sp<min)min=sp;
             }
    printf("%ld\n",min);
    //for(;;);
    return 0;
}