#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 10005
pair <int ,int> a[N];
int n ;
queue< int > q;
void work()
{
  int i , j , x;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d",&a[i].first , &a[i].second);
  LL ans = 0 , t = 0 , sum = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    x = a[i].first - t;
    while (!q.empty() && a[q.front()].second <= x)
      sum -= a[q.front()].second  ,  x -= a[q.front()].second , a[q.front()].second = 0 , q.pop();
    if (!q.empty() && x)
      a[q.front()].second -= x  , sum -= x ;
    q.push(i) , sum += a[i].second , ans = max(ans , sum);
    t = a[i].first;
  }
  while (!q.empty())
    t += a[q.front()].second , q.pop();
  cout << t << ' ' << ans;
}

int main()
{

    work();
  return 0;
}