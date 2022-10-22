#include <stdio.h>
#include <math.h>
int n,i,j;
bool f[1000005];
int main()
{
  double x,y;
  for (i = 2 ;i <= 1000000;i ++)
    if (!f[i])
      for (j = 2 ;i * j <= 1000000;j ++)
        f[i * j] = 1;
  f[1] = 1;      
  scanf("%d",&n);
  while (n --)
  {
    scanf("%lf",&x);
    y = floor(sqrt(x));
    if (x == y * y && !f[int(y)])
      printf("YES\n");
    else printf("NO\n");      
  }  
  return 0; 
}