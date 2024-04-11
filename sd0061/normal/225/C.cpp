#include <stdio.h>
#include <string.h>
#define N 1005
#define inf 1 << 29
int n,m,xx,yy,ans;
char s[N][N];
int a[N][2],f[N][N][2];
int min(int x,int y) {return x < y ? x : y;}
int main()
{
  int i,j,k,x,y;
  scanf("%d %d %d %d\n",&m,&n,&xx,&yy);
  for (i = 1 ; i <= m ;i ++)
  {
    for (j = 1 ;j <= n ;j ++)
      scanf("%c",&s[i][j]);
    getchar();        
  }  
  for (i = 1 ;i <= n ;i ++)
    for (j = 1 ;j <= m ;j ++)
      if (s[j][i] == '#')
        a[i][0] ++;
      else a[i][1] ++;  
  memset(f,15,sizeof(f));
  f[0][0][0] = f[0][0][1] = 0;
  for (i = 1 ;i <= n ;i ++)
    for (j = 1 ; j <= i ;j ++)
      for (k = 0 ;k < 2 ;k ++)
      {
        f[i][j][k] = min(f[i - 1][j - 1][k] + a[i][k],f[i][j][k]);
        if (j >= xx && j <= yy)
          f[i + 1][1][!k] = min(f[i][j][k] + a[i + 1][!k],f[i + 1][1][!k]);  
      }
  ans = inf;    
  for (i = xx ; i <= yy ;i ++)
    ans = min(ans,min(f[n][i][0],f[n][i][1]));   
  printf("%d",ans);
  return 0;
}