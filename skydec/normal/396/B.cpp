#include<stdio.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
int n;
int dx[21]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
LL Power(LL a,LL b,LL jsb)
{
            LL c=1;
            for(;b;b>>=1,a=a*1ll*a%jsb)
            if(b&1)c=c*a%jsb;
            return c;
}
bool miller(int x)
{
     for(int i=2;i*i<=x;i++)
     if(x%i==0)return 0;return 1;
}
ULL gcd(ULL a,ULL b)
{
          if(!a||!b)return a+b;
          return gcd(b,a%b);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
              int n;scanf("%d",&n);
              int bg;
              int sm;
              for(int i=n;;i--)
              {
                      if(miller(i))
                      {
                                   sm=i;
                                   break;
                                   }
                                   }
              for(int i=n+1;;i++)
              {
                      if(miller(i))
                      {
                                   bg=i;
                                   break;
                                   }
                                   }
              ULL up=sm*1ll*bg-2ll*sm-2ll*bg+2ll*n+2ll;
              ULL down=2ll*bg*sm;
              ULL c=gcd(up,down);
              up/=c;
              down/=c;
              printf("%I64d/%I64d\n",up,down);
              }
    return 0;
}