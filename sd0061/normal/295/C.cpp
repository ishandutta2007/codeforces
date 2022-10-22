#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#define N 55
typedef long long LL;
using namespace std;
int n , m , a[N] , s1 , s2;
int f[2][N][N];
long long s[2][N][N];
long long C[N][N];
const int Q = 1000000007;

bool u[2][N][N];
struct node
{
  int k , i , j;
};
queue<node> q;

void work()
{
  int i , j , k , x , y;
  scanf("%d%d",&n,&m) , m /= 50;
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]) , a[i] /= 50 , s1 += (a[i] == 1) , s2 += (a[i] == 2);
  for (i = 0 ; i <= n ; ++ i)
  {
    C[i][0] = 1;
    for (j = 1 ; j <= n ; ++ j)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j] , C[i][j] %= Q;
  }
  for (k = 0 ; k < 2 ; ++ k)
    for (j = 0 ; j <= s1 ; ++ j)
      for (i = 0 ; i <= s2 ; ++ i)
        f[k][j][i] = 1 << 30;
  f[0][0][0] = 0 , s[0][0][0] = 1;
  u[0][0][0] = 1 , q.push((node){0 , 0 , 0});

  while (!q.empty())
  {
    i = q.front().i , j = q.front().j , k = q.front().k , q.pop() , u[k][i][j] = 0;
    if (k)
    {
      for (y = 0 ; y * 2 <= m && y <= j ; ++ y)
        for (x = 0 ; x + y * 2 <= m && x <= i ; ++ x)
      {
        if (x + y * 2 == 0) continue;
        if (f[0][i - x][j - y] > f[1][i][j] + 1)
        {
          f[0][i - x][j - y] = f[1][i][j] + 1;
          s[0][i - x][j - y] = C[i][x] * C[j][y] % Q * s[1][i][j] % Q;
          if (!u[0][i - x][j - y])
            u[0][i - x][j - y] = 1 , q.push((node){0 , i - x, j - y});
        }
        else if (f[0][i - x][j - y] == f[1][i][j] + 1)
        {
          s[0][i - x][j - y] += C[i][x] * C[j][y] % Q * s[1][i][j] % Q , s[0][i - x][j - y] %= Q;
          if (!u[0][i - x][j - y])
            u[0][i - x][j - y] = 1 , q.push((node){0 , i - x, j - y});
        }
      }
    }
    else
    {
      for (y = 0 ; y + j <= s2 && y * 2 <= m ; ++ y)
        for (x = 0 ; x + i <= s1 && x + y * 2 <= m ; ++ x)
      {
              if (x + y * 2 == 0) continue;
        if (f[1][i + x][j + y] > f[0][i][j] + 1)
        {
          f[1][i + x][j + y] = f[0][i][j] + 1;
          s[1][i + x][j + y] = C[s1 - i][x] * C[s2 - j][y] % Q * s[0][i][j] % Q;
          if (!u[1][i + x][j + y])
            u[1][i + x][j + y] = 1 , q.push((node){1 , i + x, j + y});
        }
        else if (f[1][i + x][j + y] == f[0][i][j] + 1)
        {
          s[1][i + x][j + y] += C[s1 - i][x] * C[s2 - j][y] % Q * s[0][i][j] % Q , s[1][i + x][j + y] %= Q;
          if (!u[1][i + x][j + y])
            u[1][i + x][j + y] = 1 , q.push((node){1 , i + x, j + y});
        }
      }
    }
  }

  if (f[1][s1][s2] == 1 << 30)
  {
    printf("-1\n0");
    return;
  }
  cout << f[1][s1][s2] << endl << s[1][s1][s2];
}

int main()
{
  //int _;cin>>_;while(_--)
  //while (~scanf("%d%d%d",&n,&m,&Q))
    work();
  //printf("%d" ,kase );
  return 0;
}