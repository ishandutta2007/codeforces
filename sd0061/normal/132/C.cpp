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

int n , m , x;
char s[N];
bool f[N][N][2 * N][2];

void work()
{
  int i , j , k , l;
  scanf("%s" , s + 1) , n = strlen(s + 1);
  scanf("%d" , &m);
  f[0][0][N][0] = 1;

  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = 0 ; j <= m ; ++ j)
      for (k = -i ; k <= i ; ++ k)
        for (l = 0 ; l < 2 ; ++ l)
        {
          if (s[i] == 'F')
          {
            f[i][j][N + k][l] |= f[i - 1][j][N + k - (l ? 1 : -1)][l];
            f[i][j][N + k][l] |= f[i - 1][j - 1][N + k][!l];
          }
          else
          {
            f[i][j][N + k][l] |= f[i - 1][j - 1][N + k - (l ? 1 : -1)][l];
            f[i][j][N + k][l] |= f[i - 1][j][N + k][!l];
          }
        }
  }
  for (i = n ; i >= 0 ; -- i)
  {
    for (j = m ; j >= 0 ; j -= 2)
      if (f[n][j][N + i][0] || f[n][j][N - i][0] || f[n][j][N + i][1] || f[n][j][N - i][1])
        break;
    if (j >= 0) break;
  }
  printf("%d", i);

}

int main()
{
    work();
  return 0;
}