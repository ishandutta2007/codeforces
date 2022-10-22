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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 2005
int n , a[N] , ans , A , B;
bool f[N];

void dfs(int k)
{
  if (k > n)
  {
    ++ ans;
    return;
  }
  if (a[k] > 0)
    dfs(k + 1);
  else
    for (int i = 1 ; i <= n ; ++ i)
      if (!f[i] && i != k)
      {
        f[i] = 1;
        dfs(k + 1);
        f[i] = 0;
      }
}
LL d[N][N] , Q = 1e9 + 7;

LL F(int x , int y)
{
  if (d[x][y]) return d[x][y];
  if (x == 0 && y == 0) return d[x][y] = 1;
  if (y == 0) return d[x][y] = F(x - 1 , y) * x % Q;
  if (y == 1) return d[x][y] = F(x , y - 1) * x % Q;
  return d[x][y] = (F(x , y - 1) * x + F(x + 1 , y - 2) * (y - 1)) % Q;
}

void work()
{
  ans = 0;
  memset(f , 0 , sizeof(f));
  scanf("%d",&n);
  for (int i = 1 ; i <= n ; ++ i)
  {
    scanf("%d",&a[i]);
    if (a[i] > 0)
      f[a[i]] = 1;
  }
  for (int i = 1 ; i <= n ; ++ i)
    if (a[i] == -1)
    {
      if (f[i])
        ++ A;
      else ++ B;
    }
  cout << F(A , B) << endl;
}

int main()
{
  work();
  return 0;
}