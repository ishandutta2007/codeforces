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
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 200005
int n , m;
struct node
{
  char t;
  int x , y;
}q[N];
int a[N];
set< pair<int , int> > c[N];
void work()
{
  int i , j , x , y;
  char str[10];
  scanf("%d",&m);
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%s%d%d", str ,&q[i].x , &q[i].y);
    q[i].t = *str;
    a[n ++] = q[i].y;
  }
  sort(a , a + n);
  n = unique(a , a + n) - a;
  for (i = 1 ; i <= m ; ++ i)
  {
    pair<int , int> p(q[i].x , q[i].y);
    if (q[i].t == 'f')
    {
      pair<int , int> ans(1 << 30 , 1 << 30);
      for (j = upper_bound(a , a + n , q[i].y) - a + 1 ; j <= n ; j += j & -j)
      {
        set< pair<int , int> >::iterator it = c[j].upper_bound(make_pair(q[i].x , 1 << 30));
        if (it != c[j].end())
          ans = min(ans , *it);
      }
      if (ans == make_pair(1 << 30 , 1 << 30))
        puts("-1");
      else printf("%d %d\n" , ans.first , ans.second);
    }
    else
    {
      for (j = lower_bound(a , a + n , q[i].y) - a + 1 ; j ; j -= j & -j)
        if (q[i].t == 'a')
          c[j].insert(p);
        else c[j].erase(p);
    }
  }

}

int main()
{
  //while (~scanf("%d",&m))
  //int _; cin >> _;while (_--)
    work();
  return 0;
}