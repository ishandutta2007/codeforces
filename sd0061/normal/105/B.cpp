#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 105
int n , m , A;
int l[N] , p[N] , c[N];
double ans;

void cal()
{
  double sum = 0;
  for (int i = 0 ; i < 1 << n ; ++ i)
  {
    double pr = 1.0;
    int s = 0 , cnt = 0;
    for (int j = 0 ; j < n ; ++ j)
    {
      if (i & (1 << j))
        pr *= (p[j] + 10 * c[j]) / 100.0;
      else
        pr *= (100 - p[j] - c[j] * 10) / 100.0 , ++ cnt , s += l[j];
    }
    if (cnt * 2 < n )
      sum += pr;
    else
      sum += pr * A / (A + s);
  }
  ans = max(ans , sum);
}

void dfs(int d , int k)
{
  if (d >= n)
  {
    cal();
    return;
  }
  for (int i = 0 ; i <= k ; ++ i)
  {
    c[d] = i;
    if (c[d] * 10 + p[d] > 100) break;
    dfs(d + 1 , k - i);
  }
}

void work()
{
  cin >> n >> m >> A;
  for (int i = 0 ; i < n ; ++ i)
    cin >> l[i] >> p[i];
  dfs(0 , m);
  printf("%lf" , ans);
}

int main()
{
  work();
  return 0;
}