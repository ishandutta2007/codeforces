#include<stdio.h>
using namespace std;
typedef long long LL;
LL n,k,d1,d2;int t;
LL max(LL a,LL b){if(a>b)return a;return b;}
bool check(LL a,LL b)
{
     if(k-2ll*a-b<0)return 0;
     if((k-2ll*a-b)%3!=0)return 0;
     LL t1,t2,t3;
     t1=(k-2ll*a-b)/3;
     t2=t1+a;
     if(t2<0)return 0;
     t3=t2+b;
     if(t3<0)return 0;
     LL y=max(t1,max(t2,t3));
     LL need=y*2ll-(t1+t2+t3-y);
     if(n-k-need<0)return 0;
     if((n-k-need)%3!=0)return 0;
     return 1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              scanf("%I64d%I64d",&n,&k);
              scanf("%I64d%I64d",&d1,&d2);
              bool flag=0;
              flag|=check(d1,d2);
              flag|=check(-d1,-d2);
              flag|=check(d1,-d2);
              flag|=check(-d1,d2);
              if(flag)printf("yes\n");
              else printf("no\n");
              }
    return 0;
}