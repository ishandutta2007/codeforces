#include<stdio.h>
#include<cstring>
using namespace std;
typedef unsigned long long LL;
LL p,d;
int main()
{
    scanf("%I64u%I64u",&p,&d);
    for(int i=18;i>=1;i--)
    {
            LL ps=0;
            for(int j=1;j<=i;j++)
            ps*=10ll,ps+=9ll;
            LL c=1;
            for(int j=1;j<=i;j++)c*=10ll;
            LL sd=p/c;
            if(sd*c+ps<=p&&sd*c+ps>=p-d)
            {
              printf("%I64u\n",sd*c+ps);
              return 0;
              }
            sd--;
            if(sd<0)continue;
            if(sd*c+ps<=p&&sd*c+ps>=p-d)
            {
              printf("%I64u\n",sd*c+ps);
              return 0;
              }
                                      }
    printf("%I64u\n",p);
    //printf("hehe");
    return 0;
}