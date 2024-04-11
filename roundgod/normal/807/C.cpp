#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
typedef long long ll;
ll gcd(ll a,ll b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}
using namespace std;
int main()
{
 ll x,y,p,q;
 int t;
 scanf("%d",&t);
 for(int i=0;i<t;i++)
 {
   scanf("%I64d %I64d %I64d %I64d",&x,&y,&p,&q);
   q=q-p;y=y-x;
   if(p==0)
   {
       if(x==0) printf("0\n");
       else printf("-1\n");
   }
   else if(q==0)
   {
      if(y==0) printf("0\n");
      else printf("-1\n");
   }
   else
   {
       ll tmp=gcd(p,q);
       p/=tmp;
       q/=tmp;
       int c=(x-1)/p+1;
       int d=(y-1)/q+1;
       tmp=max(c,d);
       printf("%I64d\n",(p+q)*tmp-x-y);
   }
 }
 return 0;
}