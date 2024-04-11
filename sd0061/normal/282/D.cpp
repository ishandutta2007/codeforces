#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 306
using namespace std;
int n , m = 300 , a[4];
bool f[N][N] , fx[N][N][N]  , fy[N][N][N] , fz[N][N][N] , u[N][N][N];

void work()
{
  int i , j , k;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++) scanf("%d",&a[i]);
  sort(a + 1 , a + n + 1);
  if (n == 1)
  {
    puts(a[1] ? "BitLGM" : "BitAryo");
    return;
  }
  if (n == 2)
  {
    memset(f , 1 , sizeof(f));
    for (i = 0 ; i <= a[2] ; ++ i)
      for (j = 0 ; j <= a[2] ; ++ j)
        if (f[i][j])
        {
          for (k = 1 ; max(i , j) + k <= a[2] ; ++ k)
            f[i + k][j + k] = 0;
          for (k = 1 ; j + k <= a[2] ; ++ k)
            f[i][j + k] = 0;
          for (k = 1 ; i + k <= a[2] ; ++ k)
            f[i + k][j] = 0;
        }
    puts(!f[a[1]][a[2]] ? "BitLGM" : "BitAryo");
    return;
  }
  bool er;
  for (i = 0 ; i <= a[3] ; ++ i)
    for (j = 0 ; j <= a[3] ; ++ j)
      for (k = 0 ; k <= a[3] ; ++ k)
      {
        //if(!i && !j && !k) continue;
        bool x = 0;
        if (i > 0) x |= fx[i - 1][j][k];
        if (j > 0) x |= fy[i][j - 1][k];
        if (k > 0) x |= fz[i][j][k - 1];
        if (min(i,min(j ,k)) > 0) x |= u[i - 1][j - 1][k - 1];
        if (i == a[1] && j == a[2] && k == a[3]) er = x;
        if (i > 0)
          fx[i][j][k] = fx[i - 1][j][k] | (!x);
        else fx[i][j][k] = !x;
        if (j > 0)
          fy[i][j][k] = fy[i][j - 1][k] | (!x);
        else fy[i][j][k] = !x;
        if (k > 0)
          fz[i][j][k] = fz[i][j][k - 1] | (!x);
        else fz[i][j][k] = !x;

        if (min(i,min(j ,k)) > 0)
          u[i][j][k] = u[i - 1][j - 1][k - 1] | (!x);
        else u[i][j][k] = !x;
    //   printf("%d %d %d : %d\n" , i , j , k, x , fx[i][j][k] , fy[i][j][k] , fz[i][j][k] , u[i][j][k]);
      }
  puts(er ? "BitLGM" : "BitAryo");
}

int main()
{
  //while (~scanf("%s" , s + 1) , s[1] != '*')
  work();
  return 0;
}