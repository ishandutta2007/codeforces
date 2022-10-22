#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 105
int n , m;
int g[N][N] ;
long long c[N][N];
void work()
{
  int i , j , k , x , y;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= n ; ++ j)
      g[i][j] = 1 << 29;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d",&x,&y);
    g[x][y] = g[y][x] = c[x][y] = c[y][x] = 1;
  }

  for (k = 1 ; k <= n ; ++ k)
    for (i = 1 ; i <= n ; ++ i)
      for (j = 1 ; j <= n ; ++ j)
      {
        if (g[i][k] + g[k][j] < g[i][j])
          g[i][j] = g[i][k] + g[k][j] , c[i][j] = 0;
        if (g[i][k] + g[k][j] == g[i][j])
          c[i][j] += c[i][k] * c[k][j];
      }

  long long ans = c[1][n];
  for (i = 2 ; i < n ; ++ i)
    if (g[1][i] + g[i][n] == g[1][n])
      ans = max(ans , c[1][i] * c[i][n] * 2);
  printf("%.15lf\n" , 1. * ans / c[1][n]);
}

int main()
{
    work();
  return 0;
}