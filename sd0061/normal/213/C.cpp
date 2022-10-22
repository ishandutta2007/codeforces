#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define N 305
#define LL long long
int n , m , a[N][N];
int f[2][N][N];

void work()
{
  int i , j , k , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= n ; ++ j)
      scanf("%d",&a[i][j]) , f[0][i][j] = -1 << 30;
  f[0][1][1] = 0;
  for (k = 2 ; k <= n + n ; ++ k)
  {
    for (i = 1 ; i <= n ; ++ i)
      for (j = 1 ; j <= n ; ++ j)
        f[1^(k&1)][i][j] = -1 << 30;
    for (i = 1 ; i <= n ; ++ i)
      for (j = 1 ; j <= n ; ++ j) if (f[k & 1][i][j] != -1 << 30)
      {
        int& opt = f[k & 1][i][j];
        x = k - i , y = k - j;
        opt += a[i][x];
        if (i != j && x != y)
          opt += a[j][y];
        //printf("%d %d %d : %d\n" , k , i , j , f[k & 1][i][j]);
        if (i < n && j < n)
          f[1^(k&1)][i + 1][j + 1] = max(opt , f[1^(k&1)][i + 1][j + 1]);
        if (i < n && y < n)
          f[1^(k&1)][i + 1][j] = max(opt , f[1^(k&1)][i + 1][j]);
        if (x < n && j < n)
          f[1^(k&1)][i][j + 1] = max(opt , f[1^(k&1)][i][j + 1]);
        if (x < n && y < n)
          f[1^(k&1)][i][j] = max(opt , f[1^(k&1)][i][j]);
      }
  }
  cout << f[0][n][n] << endl;
}

int main()
{
  work();
  return 0;
}