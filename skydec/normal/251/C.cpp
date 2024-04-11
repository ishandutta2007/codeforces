#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long LL;
LL a,b;
LL f[400000];
int gcd(int x,int y)
{
    if(!x||!y)return x+y;
    return gcd(y,x%y);
}
void Min(LL &x,LL y){if(y<x)x=y;}
int k;
LL GO(int up,int down)
{
          memset(f,63,sizeof f);
          f[up]=0;
          for(int i=up;i>=down+1;i--)
          {
                  Min(f[i-1],f[i]+1);
                  for(int j=2;j<=k;j++)
                  Min(f[i-(i%j)],f[i]+1);
                  }
          return f[down];
}
int main()
{
    scanf("%I64d%I64d",&b,&a);
    scanf("%d",&k);
    int lcm=1;
    for(int i=2;i<=k;i++)lcm=lcm*i/gcd(lcm,i);
    LL ans=0;
    if(a/lcm==b/lcm)ans=GO(b%lcm,a%lcm);
    else ans=GO(lcm,a%lcm)+GO(b%lcm,0)+GO(lcm,0)*(b/lcm-a/lcm-1);
    printf("%I64d\n",ans);
    return 0;
}