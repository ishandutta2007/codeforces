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
#define N 5005
int n , a[N] , f[N] , ans[N] , c[N];
vector< pair<int,int> > e[N];
struct cmp
{
  bool operator ()(int x, int y) const
  {
    return a[x] < a[y];
  }
};


set<int , cmp> h[N];
pair<int , int> dep[N]; int cnt;
void dfs(int x , int fa , int d)
{
  f[x] = fa , dep[cnt ++] = mp(d , x);
  for (int i = 0 ; i < e[x].size() ; ++ i)
    if (e[x][i].fi != fa)
      c[e[x][i].fi] = e[x][i].se , dfs(e[x][i].fi , x , d + 1);
}

void work()
{
  int i , j , x , y , z;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d%d",&x,&y,&z);
    e[x].push_back(mp(y,z));
    e[y].push_back(mp(x,z));
  }
  dfs(1 , -1 , 0);
  for (i = 2 ; i <= n ; ++ i)
    h[i].insert(i);
  sort(dep , dep + cnt);
  memset(ans , -1 , sizeof(ans));
  ans[1] = 0;
  set<int , cmp>::iterator it;
  for (int t = 1 ; t <= n ; ++ t)
  {
    for (j = 1 , i = dep[j].se ; j < n ; ++ j , i = dep[j].se)
      if (h[i].size())
      {
        z = min(c[i] , (int)h[i].size());
        while (z --)
        {
          it = h[i].begin() , x = *it , h[i].erase(it);
          if (f[i] == 1) ans[x] = t;
          else h[f[i]].insert(x);
        }
      }
  }
  for (i = 1 ; i <= n ; ++ i)
    printf("%d ", ans[i]);
}

int main()
{
  work();
  return 0;
}