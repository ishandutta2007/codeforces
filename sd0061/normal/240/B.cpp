#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 205
int n,h[N],s[N] ,ans = 1 << 30;
int f[N][N * N][2],a,b;


int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i ,j ,k, x , y;
  scanf("%d%d%d",&n,&a,&b);
  for (i = 1 ;i <= n ;i ++)
    scanf("%d",&h[i]), s[i] = s[i - 1] + h[i];
  
  for (i = 1 ;i <= a ;i ++)
    f[0][i][0] = f[0][i][1] = 1 << 30;
  for (i = 1 ;i <= n ;i ++)
  {
    for (j = 0 ;j <= a;j ++)
      for (k = 0 ;k < 2 ;k ++)
      {
        x = j - h[i];
        y = s[i] - j - h[i];
        f[i][j][k] = 1 << 30;
        if (y + h[i] > b) continue;  
        if (k && y >= 0)
        {
          f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
          f[i][j][k] = min(f[i][j][k], f[i - 1][j][!k] + min(h[i], h[i - 1]));    
        }  
        if (!k && x >= 0)
        {
          f[i][j][k] = min(f[i][j][k], f[i - 1][x][k]);
          f[i][j][k] = min(f[i][j][k], f[i - 1][x][!k] + min(h[i], h[i - 1]));    
        }
      }  
  }  
  
  for (i = 0 ; i <= a ;i ++)
    for (k = 0 ;k < 2 ;k ++)    
      ans = min(ans,f[n][i][k]);
  printf("%d",ans >= 1 << 30 ? -1 : ans);    
  return 0;  
}