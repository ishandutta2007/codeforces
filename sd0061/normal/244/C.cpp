#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005

int n, ans , a[N], b[N][20] , p[20];
bool f[1 << 20];
int main()
{
  int i , j , x;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d",&a[i]);
    for (j = 0 ;j < 20 ;j ++)
    {
      if (a[i] & (1 << j))
        b[i][j] = i;
      else b[i][j] = b[i - 1][j];
      p[j] = b[i][j];
    }
    sort(p , p + 20);
    x = a[i];
    f[x] = 1;
    for (j = 19 ; j > -1 ;j --)
      x |= a[p[j]] , f[x] = 1;
  }
  for (i = 0 ;i < 1 << 20 ;i ++)
    if (f[i])
      ans ++;
  printf("%d",ans);
  return 0;
}