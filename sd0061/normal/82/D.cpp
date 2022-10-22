#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 1005
using namespace std;
typedef long long LL;

int n , a[N] , f[N][N];
void print(int i , int j)
{
  if (i > n || j > n) return;
  if (f[i][j] == f[j + 1][j + 2] + max(a[i] , a[j]))
  {
    if (a[j] == 0)
      printf("%d\n" , i);
    else printf("%d %d\n" , i , j);
    print(j + 1 , j + 2);
    return;
  }
  if (f[i][j] == f[j][j + 2] + max(a[i] , a[j + 1]))
  {
    if (a[j + 1] == 0)
      printf("%d\n" , i);
    else printf("%d %d\n" , i , j + 1);
    print(j , j + 2);
    return;
  }
  if (f[i][j] == f[i][j + 2] + max(a[j] , a[j + 1]))
  {
    if (a[j + 1] == 0)
      printf("%d\n" , j);
    else printf("%d %d\n" , j , j + 1);
    print(i , j + 2);
    return;
  }
}
void work()
{
  int i , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d" , &a[i]);
  if (n & 1) a[++ n] = 0;

  for (i = n ; i > 0 ; -- i)
    for (j = n ; j > i ; -- j)
    {
      f[i][j] = 1 << 30;
      f[i][j] = min(f[i][j] , f[j + 1][j + 2] + max(a[i] , a[j]));
      if (j != n)
      {
        f[i][j] = min(f[i][j] , f[j][j + 2] + max(a[i] , a[j + 1]));
        f[i][j] = min(f[i][j] , f[i][j + 2] + max(a[j] , a[j + 1]));
      }
    }
  printf("%d\n" , f[1][2]);
  print(1 , 2);
}

int main()
{
    work();
  return 0;
}