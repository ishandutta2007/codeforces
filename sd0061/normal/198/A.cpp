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

int k , b , n , t;
void work()
{
  long long count = 1;
  while (count <= t)
  {
    count = count * k + b;
    -- n;
  }
  printf("%d\n" , max(n + 1 , 0));
}
int main()
{
  while (cin >> k >> b >> n >> t)
    work();
  return 0;
}