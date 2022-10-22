#include <stdio.h>
#include <string.h>
int n , k ,a[55] , ans;
int main()
{
  scanf("%d%d",&n ,&k);
  for (int i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);  
  for (int i = 1 ; i <= n ;i ++)
    if (a[i] >= a[k] && a[i] > 0)
      ans ++;  
  printf("%d",ans);
  return 0;
}