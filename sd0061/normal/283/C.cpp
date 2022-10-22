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
#define N 305
using namespace std;
int n , m , a[N] , d[N] , p[N] , r[N];
vector<int> e[N] , g[N];
long long t , f[100005];
const int Q = 1e9 + 7;
void work()
{
  int i , j , x , y;
  scanf("%d%d%I64d",&n,&m,&t);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);
  for (i = 1 ; i <= m ;i ++)
  {
    scanf("%d%d",&x,&y); // x > y
    ++ d[x] , e[y].pb(x) , ++ r[y] , g[x].pb(y);
  }
  queue<int> q;
  int sum = 0;
  for (i = 1 ; i <= n; i ++)
    if (!d[i])
      p[i] = -1 , q.push(i) , ++ sum;
  while (!q.empty())
  {
    x = q.front() , q.pop() , ++ p[x] , t -= (long long)a[x] * p[x];
    for (i = 0 ;i < e[x].size() ; ++ i)
    {
      y = e[x][i];
      p[y] = max(p[y] , p[x]);
      if (!-- d[y])
        ++ sum , q.push(y);
    }
  }
  if (t < 0 || sum != n)
  {
    printf("0");
    return;
  }

  for (i = 1 ; i <= n; i ++)
    if (!r[i])
      q.push(i);
  while (!q.empty())
  {
    x = q.front() , q.pop();
    for (i = 0 ;i < g[x].size() ; ++ i)
    {
      y = g[x][i] , a[y] += a[x];
      if (!-- r[y])
        q.push(y);
    }
  }

  f[0] = 1;
  for (i = 1 ; i <= n ; ++ i)
    for (j = a[i] ; j <= t ; ++ j)
      f[j] += f[j - a[i]] , f[j] %= Q;
  printf("%I64d\n", f[t]);
}

int main()
{
    work();
  return 0;
}