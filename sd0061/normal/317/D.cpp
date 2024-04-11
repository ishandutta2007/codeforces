#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
int n;

int dfs(int x)
{
  int i  , j , y;
  for (i = 1 ; i <= n ; ++ i) if (~x & (1 << (i - 1)))
  {
    y = x;
    if (i == 1)
      y = x | 1;
    else
    for (j = i ; j <= n ; j *= i)
      y |= (1 << (j - 1));
    if (!dfs(y))
      return 1;
  }
  return 0;
}
int SG[40] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
bool f[50000];
void work()
{
  int i , k , tot = 0;
  cin >> n;
  int ans = 0 ;
  for (i = 2 ; i * i <= n ; ++ i) if (!f[i])
  {
    long long j = i ; k = 1;
    for ( ; j <= n ; j *= i , ++ k) if(j * j <= n)f[j] = 1;
    tot += k - 1;
    ans ^= SG[k - 1];
  }
  -- i;
  ans ^= (n - tot) & 1;
 // if (!ans) cout << n << endl;
  puts(ans ? "Vasya" : "Petya");
}

int main()
{
  work();
  return 0;
}