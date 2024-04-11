#include<stdio.h>
using namespace std;
long n,k;
int main()
{
    scanf("%ld%ld",&n,&k);long ans=0;
    for(long i=1;i<=n;i++)
    {
             long u;scanf("%ld",&u);long pp=0;
             while(u)
             {
                     if(u%10==4||u%10==7)pp++;
                     u/=10;
                     }
             if(pp<=k)ans++;
             }
    printf("%ld\n",ans);
    return 0;
}