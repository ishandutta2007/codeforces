#include <stdio.h>
#include <string.h>
#define N 105
int n;
int work(int a,int b)
{
  if ((a == 1 || a == 2 || a == 6 || a == 5) && (b == 1 || b == 2 || b == 6 || b == 5))
    return 3;
  if ((a == 1 || a == 3 || a == 6 || a == 4) && (b == 1 || b == 3 || b == 6 || b == 4))
    return 2;
  if ((a == 3 || a == 2 || a == 5 || a == 4) && (b == 3 || b == 2 || b == 5 || b == 4))
    return 1;    
}
int main()
{
  int i,x,y,a,b;  
  scanf("%d %d",&n,&x);
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%d %d",&a,&b);
    y = work(a , b);
    if (y != x && y != 7 - x)
      break;
  }  
  if (i <= n)
    printf("NO");
  else printf("YES");
  return 0;  
}