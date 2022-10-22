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
#define N 3005
#define LL long long

int n;
vector<int> e[N];
int fa[N] , u[N];

int dfs(int x , int f)
{
  u[x] = f;
  int temp = 0;
  for (int i = 0 ; i < e[x].size() ; ++ i)
  {
    if (e[x][i] == x || fa[x] == e[x][i]) continue;
    if (u[e[x][i]])
      return u[e[x][i]];
    fa[e[x][i]] = x;
    temp = dfs(e[x][i] , f + 1);
    if (~temp) return temp;
  }
  return -1;
}

void work()
{
  int i , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%d%d",&x , &y);
    e[x].pb(y) , e[y].pb(x);
  }
  for (i = 1 ; i <= n ; ++ i)
  {
    memset(u , 0 , sizeof u);
    memset(fa , 0 , sizeof fa);
    printf("%d " , dfs(i , 1) - 1);
  }
}

int main()
{
  work();
  return 0;
}