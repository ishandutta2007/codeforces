#include <stdio.h>
#include <string.h>
int n;
int main()
{
  scanf("%d",&n);
  if (n >= 4 && n % 2 == 0)
    printf("YES");
  else printf("NO");  
  return 0;
}