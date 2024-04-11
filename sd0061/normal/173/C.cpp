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
#define N 505

int n , m , a[N][N] , s[N][N] , f[N][N];

int get(int x , int y , int xx , int yy)
{
  return s[xx][yy] + s[x - 1][y - 1] - s[xx][y - 1] - s[x - 1][yy];
}

void work()
{
  int i , j , k;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      scanf("%d",&a[i][j]) , s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1] , f[i][j] = a[i][j];
  int ans = -2147483648;
  for (k = 0 ; 2 * k + 3 <= min(n , m) ; ++ k)
  {
    for (i = 1 ; i + (2 * k + 2) <= n ; ++ i)
      for (j = 1 ; j + (2 * k + 2) <= m ; ++ j)
      {
        f[i][j] = get(i , j , i + (2 * k + 2) , j + (2 * k + 2)) - f[i + 1][j + 1] - a[i + 1][j];
        ans = max(ans , f[i][j]);
      }
  }
  printf("%d", ans);

}

int main()
{
    work();
  return 0;
}