#include <stdio.h>
#include <string.h>
int n,m,d[1000005];
long long ans;

int main()
{
  int i;
  long long x,y;
  scanf("%d %d",&n,&m);
  while (m --)
    scanf("%d",&i) , d[i] ++ ,
    scanf("%d",&i) , d[i] ++ ;
  for (i = 1 ;i <= n ;i ++)
  {
    x = d[i] , y = n - d[i] - 1;
    ans += x * (x - 1) - x * y + y * (y - 1); 
  }    
  printf("%I64d",ans/6);
  return 0;
}