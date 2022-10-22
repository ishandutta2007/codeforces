#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 200005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n , k , p;
struct node
{
  int x , y , n;
  bool operator < (const node& r) const{
    return make_pair(x , make_pair(y , n)) < make_pair(r.x , make_pair(r.y , r.n));}
}a[N];

bool cmp(node a , node b)
{
  return make_pair(a.y , -a.x) < make_pair(b.y , -b.x);
}

void work()
{
  int i , j;
  cin >> n >> k >> p;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i].x >> a[i].y , a[i].n = i + 1;
  sort(a , a + n , cmp);
  set< node > h;
  LL ans = 0;
  LL sum = 0;
  for (i = n - 1 ; i >= 0 ; -- i)
  {
    h.insert(a[i]) , sum += a[i].x;
    if (h.size() > p)
      sum -= (*h.begin()).x , h.erase(h.begin());
    if (h.size() == p && i >= k - p)
      ans = max(sum , ans);
  }
  h.clear();
  sum = 0;
  for (i = n - 1 ; i >= 0 ; -- i)
  {
    h.insert(a[i]) , sum += a[i].x;
    if (h.size() > p)
      sum -= (*h.begin()).x , h.erase(h.begin());
    if (h.size() == p && i >= k - p)
      if (sum == ans)
      {
        for (j = i - 1 ; j >= i - k + p ; -- j)
          printf("%d " , a[j].n);
        while (h.size())
          printf("%d " , (*h.begin()).n) , h.erase(h.begin());
        return;
      }
  }

}

int main()
{
    work();
  return 0;
}