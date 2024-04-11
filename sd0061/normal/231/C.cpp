#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100005
int n ,K;
long long a[N] ,s[N] ,ansl , ansx ,x , y;

int main()
{
  int i ,j, l , r , m;  
  scanf("%d %d",&n,&K);
  for (i = 1 ;i <= n ;i ++)
    scanf("%I64d",&a[i]);
  sort(a + 1, a + n + 1);
  for (i = 1 ;i <= n ;i ++)
    s[i] = s[i - 1] + a[i];
  a[n + 1] = -1;  
  for (i = 1; i <= n ;i ++)
    if (a[i] != a[i + 1])
    {
      x = a[i];
      l = 1, r = i , y = K + s[i]; 
      while (l <= r)
      {
        m = (l + r) >> 1;
        if (m * x + s[i - m] <= y && ((m == i)||((m + 1) * x + s[i - m - 1] > y)))
          break;
        else if (((m != i) &&((m + 1) * x + s[i - m - 1] <= y)))
          l = m + 1;
        else if (m * x + s[i - m] > y)
          r = m - 1;        
      }
      if (l > r)
        continue;
      if (m > ansl)
      {
        ansl = m;
        ansx = x;    
      }
      if (m == ansl && ansx > x)
        ansx = x;
   /*   printf("%I64d::" , K + s[i]);
      for (j = 1 ;j <= i ;j ++)
        printf("%I64d ",j * x + s[i - j]);
      printf("\n");        */ 
    }
  printf("%I64d %I64d",ansl,ansx);  
  return 0;    
}
 /*3::0 
5::2 4 
8::5 6 9 
12::9 10 12 16 
18::15 17 20 24 30 
*/