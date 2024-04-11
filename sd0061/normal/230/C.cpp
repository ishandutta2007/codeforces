#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 20005
int n,m,ans;
bool a[105][N >> 1];
int l[105][N] , r[105][N];
int main()
{
  int i, j ,x;  
  char c;
  scanf("%d %d\n",&n,&m);
  for (i = 1 ;i <= n ;i ++)
  {
    for (j = 0 ;j < m ;j ++)
      c = getchar() , a[i][j] = bool(c - '0');
    getchar();    
  }
  
  for (i = 1 ;i <= n ;i ++)
  {
    for (j = 0 ;j < m << 1 ;j ++)
      if (a[i][j % m])
        l[i][j] = 0;
      else if (j != 0)
        l[i][j] = l[i][j - 1] + 1;
      else l[i][j] = 1 << 20;      
    for (j = (m << 1) - 1;j >= 0 ;j --)
      if (a[i][j % m])
        r[i][j] = 0;
      else if (j != (m << 1) - 1)
        r[i][j] = r[i][j + 1] + 1;
      else r[i][j] = 1 << 20;      
  }
  ans = 1 << 20;
  for (j = 0 ;j < m ;j ++)
  {
    x = 0;  
    for (i = 1 ;i <= n; i ++)
      x += min(min(l[i][j],l[i][j + m]), min(r[i][j],r[i][j + m]));
    ans = min(ans,x);    
  }
  if (ans >= 1 << 20)
    ans = -1;
  printf("%d",ans);
  return 0;
}