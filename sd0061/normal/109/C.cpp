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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define LL long long
int n , f1[N] , f2[N] , c[N];
LL ans;
vector< pair<int , bool> > e[N];

bool check(int x)
{
  while (x)
  {
    if (x % 10 != 4 && x % 10 != 7)
      return 0;
    x /= 10;
  }
  return 1;
}

void dfs1(int x , int fa)
{
  c[x] = 1; int y;
  for (int i = 0 ; i < e[x].size() ; ++ i)
    if (e[x][i].fi != fa)
    {
      y = e[x][i].fi;
      dfs1(y , x);
      c[x] += c[y];
      if (e[x][i].se)
        f1[x] += c[y] , f2[y] = n - c[y];
      else f1[x] += f1[y];
    }
}
void dfs2(int x , int fa)
{
  int y;
  for (int i = 0 ; i < e[x].size() ; ++ i)
    if (e[x][i].fi != fa)
    {
      y = e[x][i].fi;
      if (e[x][i].se)
        f2[y] = n - c[y];
      else f2[y] = f2[x] + f1[x] - f1[y];
      dfs2(y , x);
    }
}

void work()
{
  int i , x , y , z;
  scanf("%d",&n);
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d%d",&x,&y,&z);
    z = check(z);
    e[x].push_back(mp(y , z));
    e[y].push_back(mp(x , z));
  }
  dfs1(1 , -1);
  dfs2(1 , -1);
  for (i = 1 ; i <= n ; ++ i)
    ans += (LL) (f1[i] + f2[i]) * (f1[i] + f2[i] - 1);
  cout << ans << endl;
}


int main()
{
  work();
  return 0;
}