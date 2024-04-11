#include <stdio.h>
#include <string.h>

long long n,m;

long long p(int x)
{
  if (x == 0)
    return 1;
  long long q = p(x >> 1);
  q *= q, q %= m;  
  if (x & 1)
    return (q  * 3) % m;
  else return q;       
}

int main()
{
  scanf("%I64d %I64d",&n,&m);
  long long w = p(n) - 1;
  if (w != -1)
    printf("%d",w);
  else printf("%d",m - 1);
  //getchar();getchar();
  return 0;    
}