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
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 205
#define LL long long
int a[N] , p[N] , n , m , l;
double f[N][N][N + N];

void work()
{
  int i , j , k;
  cin >> n >> l >> m;
  for (i = 1 ; i <= n ; ++ i)
    cin >> p[i];
  for (i = 1 ; i <= n ; ++ i)
    cin >> a[i];
  f[0][0][min(m , n) + n] = 1;

  for (i = 0 ; i < n ; ++ i)
    for (j = 0 ;j <= n ; ++ j)
      for (k = -n ; k <= n ; ++ k) if (f[i][j][k + n] != 0)
      {
       // printf("%d %d %d : %lf\n" , i , j , k , f[i][j][k + n]);
        f[i + 1][j][k + n] += f[i][j][k + n] * (100 - p[i + 1]) / 100;
        f[i + 1][j + 1][min(k + a[i + 1] , n) + n] += f[i][j][k + n] * p[i + 1] / 100;
      }
  double ans = 0;
  for (k = l ; k <= n ; ++ k)
    for (j = 0 ;j <= n ; ++ j)
    ans += f[n][k][j + n];
  printf("%.9lf" , ans);
}


int main()
{
    work();
  return 0;
}