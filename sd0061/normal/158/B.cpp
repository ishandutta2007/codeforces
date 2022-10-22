#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,a[5];
int main()
{
  int i ,j , ans;  
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&j) , a[j] ++;
  ans = a[4];
  j = min(a[1],a[3]);
  ans += j;
  a[1] -= j , a[3] -= j;
  ans += a[3];

  ans += a[2] / 2 , a[2] %= 2; 
  if (a[2])
    ans += a[2] , a[1] -= 2;
  if (a[1] > 0)
    ans += a[1] / 4 , a[1] %= 4;
  if (a[1] > 0) ans ++;  
  printf("%d",ans);
  return 0;
}