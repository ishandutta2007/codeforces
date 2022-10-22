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
#define N 3
using namespace std;
typedef long long LL;
int n , m , x , y;


int work()
{
  int ans = 0;

  int b = x % m;
  if (b == 0) b = m;
  int a = x / m + (b != m);

  int d = y % m;
  if (d == 0) d = m;
  int c = y / m + (d != m);

  if (a == c) return 1;
  if (b == 1 && (d == m || y == n)) return 1;

  if (x == 1)
  {
    if (c == 1)
      return 1;
    if (d == m)
      return 1;
    if (y == n)
      return 1;
    return 2;
  }

  if (a + 1 == c)
    return 2;
  if (d + 1 == b)
    return 2;
  if (b == 1) return 2;
  if (d == m) return 2;
  if (y == n) return 2;
  return 3;


}

int main()
{
  //int _;cin >> _; while (_--)
  while (cin >> n >> m >> x >> y)
  printf("%d",work());
  return 0;
}