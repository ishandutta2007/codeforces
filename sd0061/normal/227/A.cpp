#include <stdio.h>
#include <string.h>

long long x1,x2,x3,y11,y2,y3;
int main()
{
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d ",&x1,&y11,&x2,&y2,&x3,&y3);
  x3 -= x2 , y3 -= y2;
  x2 -= x1 , y2 -= y11;  
  x1 = x2 * y3 - x3 * y2;
  if (x1 < 0)
    printf("RIGHT");
  if (x1 == 0)
    printf("TOWARDS");
  if (x1 > 0)
    printf("LEFT");
  return 0;  
}