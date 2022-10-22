#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long LL;
using namespace std;
LL n , X , Y , C;

LL cal(LL x , LL y , LL t) // x <= y
{
  if (x > y) swap(x , y);
  if (t <= x) return t * (t + 1) / 2;
  if (t <= y) return x * (t - x) + x * (x + 1) / 2;
  if (t <= x + y - 1)  return x * (t - x) + x * (x + 1) / 2 - (t - y) * (t - y + 1) / 2;
  return x * y;
}
int main()
{
  LL l , r , m;
  scanf("%I64d%I64d%I64d%I64d",&n,&X,&Y,&C);
  l = 0 , r = 1LL << 32;
  while (l < r)
  {
    m = (l + r) >> 1;
    LL s = 1 + cal(1 , X - 1 , m) + cal(1 , n - X , m ) + cal(1 , Y - 1 , m) + cal(1 , n - Y , m) +
           cal(X - 1 , Y - 1 , m - 1) + cal(X - 1 , n - Y , m - 1) + cal(n - X , Y - 1 , m - 1) + cal(n - X , n - Y , m - 1);
    if (s >= C)
      r = m;
    else l = m + 1;
  }
  cout << l << endl;
  return 0;
}