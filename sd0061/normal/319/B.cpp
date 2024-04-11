#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define N 100005
#define M 500005
#define LL long long

int n , a[N] , next[N] , cnt , prev[N];
deque<int> q[N];
int p[N] , m;
void work()
{
  int i , x , ans = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  a[0] = -1 << 30 , cnt = 1;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (a[i - 1] > a[i])
      next[cnt] = cnt + 1 , ++ cnt , prev[cnt] = cnt - 1;
    q[cnt].push_back(a[i]);
  }next[0] = 1;
  for (ans = 0 ; cnt > 1 ; ++ ans)
  {
    m = 0;
    for (i = next[0] ; next[i] ; i = next[i])
    {
      if (q[i].back() > q[next[i]].front())
        p[++ m] = next[i];
    }
    if (!m) break;
    for (i = 1 ; i <= m ; ++ i)
    {
      x = p[i];
      q[x].pop_front();
      if (q[x].empty())
        prev[next[x]] = prev[x] , next[prev[x]] = next[x] , -- cnt;
    }
  }
  cout << ans << endl;
}

int main()
{
    work();
  return 0;
}