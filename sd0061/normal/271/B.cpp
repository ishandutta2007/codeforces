#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100050
#define M 502
int n , m , f[N] , a[M][M], r[M] , c[M] , ans = 1 << 30;
vector<int> p;

void work()
{
  int i , j , x;
  for (i = 2 ; i * i <= 100020 ; ++ i) if (!f[i])
    for (j = i << 1 ; j <= 100020 ; j += i)
      f[j] = 1;
  for (i = 2 ; i <= 100020 ; ++ i) if (!f[i])
    p.pb(i);
  cin >> n >> m;
  for (i = 1 ; i <= n ;i ++)
    for (j = 1 ; j <= m ;j ++)
    {
      cin >> a[i][j];
      x = p[lower_bound(p.begin() , p.end() , a[i][j]) - p.begin()];
      a[i][j] = x - a[i][j];
      r[i] += a[i][j] , c[j] += a[i][j];
    }
  for (i = 1 ; i <= n ;i ++)
    ans = min(ans , r[i]);
  for (j = 1 ; j <= m ;j ++)
    ans = min(ans , c[j]);
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}