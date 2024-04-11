#include <stdio.h>
#include <string.h>
int n;
int main()
{
  scanf("%d",&n);
  if (n % 2 == 1)
    printf("-1");
  else
    for (int i = 1 ;i <= n ;i += 2)
      printf("%d %d ",i + 1 , i);
  return 0;        
}