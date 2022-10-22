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
#define N 100005
using namespace std;
typedef long long LL;

int n , a[N];
int b[N] , c[N] , m;
void work()
{
  int i , j , x;
  scanf("%d",&m);
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d" ,&b[i]);
  for (i = 1 ; i <= m ; ++ i)
    if (i == 1 || b[i] != b[i - 1])
      a[++ n] = b[i] , c[n] = i;

  for (i = 1 ; i < n ; ++ i)
    if (a[i] > a[i + 1])
      break;
  for (j = 1 ; j < n ; ++ j)
    if (a[j] < a[j + 1])
      break;
  if (i >= n || j >= n)
  {
    printf("0\n");
    return;
  }
  for (i = 1 ; i + 1 < n ; ++ i)
    if (a[i] > a[i + 1] && a[i + 1] < a[i + 2])
    {
      printf("3\n%d %d %d" , c[i] , c[i + 1] , c[i + 2]);
      return;
    }
  for (i = 1 ; i + 1 < n ; ++ i)
    if (a[i] < a[i + 1] && a[i + 1] > a[i + 2])
    {
      printf("3\n%d %d %d" , c[i] , c[i + 1] , c[i + 2]);
      return;
    }
}

int main()
{
    work();
  return 0;
}