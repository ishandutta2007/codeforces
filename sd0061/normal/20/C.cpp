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
using namespace std;
#define N 100005
int n , m ,  p[N];
long long d[N];
bool f[N];
struct edge
{
  int x , w;
};
vector<edge> e[N];
deque<int> q;

void Bellman_Ford(int st)
{
  int i , x , y , z;
  for (i = 1 ; i <= n; ++ i)
    d[i] = 1LL << 60 , f[i] = 0;
  d[st] = 0 , f[st] = 1 , q.push_back(st);
  while (!q.empty())
  {
    x = q.front() , q.pop_front() , f[x] = 0;
    for (i = e[x].size() - 1 ;i >= 0;-- i)
    {
      y = e[x][i].x , z = e[x][i].w;
      if (d[y] > d[x] + z)
      {
        d[y] = d[x] + z , p[y] = x;
        if (!f[y])
        {
          if (q.empty() || d[y] < d[q.front()])
            q.push_front(y);
          else q.push_back(y);
          f[y] = 1;
        }
      }
    }
  }
}

void print(int x)
{

  if (x != 1)
    print(p[x]);
  printf("%d",x);
  if (x != n) printf(" ");
}

void work()
{
  int i , x , y , z , ans = 0;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= m ;i ++)
  {
    scanf("%d%d%d",&x,&y,&z);
    e[x].pb((edge){y , z});
    e[y].pb((edge){x , z});
  }
  Bellman_Ford(1);
  if (d[n] == 1LL << 60) puts("-1"); else
  print(n);
}

int main()
{
    work();
  return 0;
}