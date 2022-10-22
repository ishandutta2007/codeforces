#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 1005
int n , m , k;
char s[N][N];
int f[4][N][N];
int xx[26] , yy[26];
int com[100005];
char dir[100005];

void work()
{
  int i , j; char str[5];
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);
  scanf("%d",&k);
  for (i = 1 ; i <= k ; ++ i)
    scanf("%s %d" , str , &com[i]) , dir[i] = str[0];

  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (s[i][j] == '#')
        f[0][i][j] = f[1][i][j] = 0;
      else f[0][i][j] = f[0][i - 1][j] + 1 , f[1][i][j] = f[1][i][j - 1] + 1;
  for (i = n ; i > 0 ; -- i)
    for (j = m ; j > 0 ; -- j)
      if (s[i][j] == '#')
        f[2][i][j] = f[3][i][j] = 0;
      else f[2][i][j] = f[2][i + 1][j] + 1 , f[3][i][j] = f[3][i][j + 1] + 1;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (isupper(s[i][j]))
         xx[s[i][j] - 'A'] = i , yy[s[i][j] - 'A'] = j;
  bool u = 0;
  for (i = 0 ; i < 26 ; ++ i) if (xx[i])
  {
    int x = xx[i] , y = yy[i];
    for (j = 1 ; j <= k ; ++ j)
    {
      if (dir[j] == 'N')
      {
        if (f[0][x][y] > com[j])
          x -= com[j];
        else break;
      }
      if (dir[j] == 'S')
      {
        if (f[2][x][y] > com[j])
          x += com[j];
        else break;
      }
      if (dir[j] == 'W')
      {
        if (f[1][x][y] > com[j])
          y -= com[j];
        else break;
      }
      if (dir[j] == 'E')
      {
        if (f[3][x][y] > com[j])
          y += com[j];
        else break;
      }
    }
    if (j > k) putchar('A' + i) , u = 1;
  }
  if (!u) puts("no solution");
}

int main()
{
  work();
  return 0;
}