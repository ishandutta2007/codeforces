#include <stdio.h>
#include <string.h>
#include <math.h>
long long n;long long x,y;

long long fac(long long y)
{
  int ans = 0;  
  while (y)  
    ans += y % 10 , y /= 10;
  return ans;  
}

long long cal(long long m,double x)
{
  double deta = sqrt( double(x * x + 4 * n) ) - x;  
  return (long long) (deta * 0.5);
}

int main()
{
  scanf("%I64d",&n);
  x = cal(n, 81.0);
  y = cal(n, 1.0);
  if (x < 1) x = 1;
  for (long long i = x ; i <= y ; i ++)
    if (n % i == 0 && n / (long long) i == (i + fac(i)))
    {
      printf("%I64d",i);
      return 0;    
    }
  printf("-1");  
  return 0;        
}