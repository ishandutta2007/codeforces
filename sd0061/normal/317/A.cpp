#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
long long x , y , m , a;

void work()
{
  long long ans = 0;
  cin >> x >> y >> m;
  if (x > y) swap(x , y);
  if (m <= y)
  {
    puts("0");
    return;
  }
  if (y <= 0)
  {
    puts("-1");
    return;
  }
  if (x <= 0)
  {
    ans = (-x) / y;
    x = x + ans * y;
  }
  while (1)
  {
    if (x > y) swap(x , y);
    if (y >= m) break;
    a = x + y;
    x = y , y = a , ++ ans;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}