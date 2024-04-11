


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
#define N 20005
using namespace std;
int n , d[7] , a[N] , b[N] , sum;
bool u[7] , v[N];
int f[7];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
vector<pair<int ,int> > e[7];
vector<pair<int ,char> > ans;

void dfs(int x , int z)
{
  for (int i = 0 ; i < d[x] ; ++ i)
    if (!v[e[x][i].second])
    {
      v[e[x][i].second] = 1;
      dfs(e[x][i].first , e[x][i].second);
    }
  if (z != -1)
    ans.pb(mp(z , x != a[z]? '+' : '-'));
}

void work()
{
  int i , j , x , y , z;
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d%d",&x,&y) , a[i] = x , b[i] = y;
    if (!u[x]) u[x] = 1, ++ sum , f[x] = x;
    if (!u[y]) u[y] = 1, ++ sum , f[y] = y;
    if (getf(x) != getf(y))
      -- sum , f[getf(x)] = getf(y);
    ++ d[x] , ++ d[y];
    e[x].pb(mp(y , i)) , e[y].pb(mp(x , i));
  }
  z = 0;
  for (i = 0 ; i < 7 ; ++ i)
    if (d[i] & 1)
      ++ z;
  if ((z != 0 && z != 2) || sum != 1)
  {
    printf("No solution\n");
    return;
  }
  if (z == 2)
  {
    for (i = 0 ; i < 7 ; ++ i)
      if (d[i] & 1)
      {
        x = i;
        break;
      }
  }
  else
  {
    for (i = 0 ; i < 7 ; ++ i)
      if (d[i])
      {
        x = i;
        break;
      }
  }
  dfs(x , -1);
  for (i = ans.size() - 1 ; i >= 0 ; i --)
    printf("%d %c\n",ans[i].first , ans[i].second);
}

int main()
{
  scanf("%d",&n);
  work();
  return 0;
}