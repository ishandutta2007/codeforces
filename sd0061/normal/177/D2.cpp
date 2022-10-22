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
#define N 200005
using namespace std;
typedef long long LL;

#define sqr(x) ((x)*(x))
int n , a[N] , b[N] , m , c;

void work()
{
  int i , l , r;
  scanf("%d%d%d",&n,&m,&c);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d",&b[i]) , b[i] += b[i - 1] , b[i] %= c;
  //l = r = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (i + m - 1 <= n)
      l = 1;
    else l = i - n + m;

    if (i - m + 1 > 0)
      r = m;
    else r = i;

    a[i] = (a[i] + b[r] - b[l - 1] + c) % c;
    printf("%d " , a[i]);
  }
}

int main()
{
    work();
  return 0;
}