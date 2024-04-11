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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 200005

int n , pre[N] , mcnt , m , D , d[N];
bool vit[N];
struct edge
{
  int x , next;
}e[N << 1];
pair<int , int> f1[N] , f2[N];

void dfs1(int x , int fa)
{
  if (vit[x])
    f1[x] = make_pair(0 , x);
  else f1[x] = make_pair(-1 << 30 ,0);
  f2[x] = make_pair(-1 << 30 , 0);
  for (int i = pre[x] ; ~i ; i = e[i].next)
    if (e[i].x != fa)
    {
      dfs1(e[i].x , x);
      pair<int , int> tmp(f1[e[i].x].fi + 1 , e[i].x);
      if (tmp > f1[x])
        f2[x] = f1[x] , f1[x] = tmp;
      else if (tmp > f2[x])
        f2[x] = tmp;
    }
}

void dfs2(int x , int fa)
{
  for (int i = pre[x] ; ~i ; i = e[i].next)
    if (e[i].x != fa)
    {
      if (e[i].x == f1[x].se)
        d[e[i].x] = max(d[e[i].x] , max(d[x] , f2[x].fi) + 1);
      else d[e[i].x] = max(d[e[i].x] , max(d[x] , f1[x].fi) + 1);
      dfs2(e[i].x , x);
    }
}

void work()
{
  int i , x , y;
  scanf("%d%d%d",&n,&m,&D);
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d",&x) , vit[x] = 1;
  for (i = 1 ; i <= n ; ++ i)
    if (!vit[i])
      d[i] = -1 << 30;
  memset(pre , -1 , sizeof(pre));
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d",&x,&y);
    e[mcnt] = (edge){y , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge){x , pre[y]} , pre[y] = mcnt ++;
  }
  dfs1(1 , 0);
  dfs2(1 , 0);
  int ans = 0;
  for (i = 1 ; i <= n ; ++ i)
    if (max(d[i] , f1[i].fi) <= D)
      ++ ans;
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}