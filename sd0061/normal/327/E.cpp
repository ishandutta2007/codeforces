#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define N 25
#define LL long long
LL Q = 1000000007;
int n , k;
LL a[1 << 24];
LL sum[1 << 24] , f[1 << 24];
LL p[N];
void work()
{
  int i , j , x;
  scanf("%d",&n);
  for (i = 0 ; i < n ; ++ i)
    scanf("%I64d",&a[1 << i]);
  scanf("%d",&k);
  for (i = 0 ; i < k ; ++ i)
    scanf("%I64d",&p[i]);

  for (i = 0 ; i < 1 << n ; ++ i)
  {
    x = i;
    while (x)
      j = x & (-x) , sum[i] += a[j] , x -= j;
  }
  f[0] = 1;
  for (i = 1 ; i < 1 << n ; ++ i)
  {
    for (j = 0 ; j < k ; ++ j)
      if (p[j] == sum[i])
        break;
    if (j < k) continue;
    x = i;
    while (x)
      j = x & (-x) , f[i] += f[i & ~j] , f[i] >= Q ? f[i] -= Q : i , x -= j;
  }
  cout << f[(1 << n) - 1];
}

int main()
{
   work();
   return 0;
}