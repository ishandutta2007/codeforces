#include<stdio.h>
#include<cmath>
using namespace std;
long a,b;
bool issq(long x)
{
     long s=(long)sqrt(x);
     return s*s==x;
}
int main()
{
    scanf("%ld%ld",&a,&b);
    for(long i=1;i*i<a*a;i++)
    if(issq(a*a-i*i)&&(b*i%a==0)&&issq(b*b-(b*i/a)*(b*i/a)))
    if(i!=(long)sqrt(b*b-(b*i/a)*(b*i/a)))
    {
      printf("YES\n");
      printf("0 0\n");
      printf("%ld %ld\n",-(long)sqrt(a*a-i*i),i);
      printf("%ld %ld\n",b*i/a,(long)sqrt(b*b-(b*i/a)*(b*i/a)));
      return 0;
      }
    printf("NO\n");
    return 0;
}