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
#define N 200005
int n ,  m , cur[N];
bool d[N];
struct edge
{
  int x , f , p;
  bool d;
};
vector<edge> e[N];
queue<int> q;

void work()
{
  int i , x , y , z;
  scanf("%d%d",&n,&m);
  for (i = 1 ;i <= m ; ++ i)
  {
    scanf("%d%d%d",&x,&y,&z);
    e[x].pb((edge){y , z , i , 1});
    e[y].pb((edge){x , z , i , 0});
    cur[x] += z , cur[y] += z;
  }
  for (i = 2 ;i < n ; ++ i)
    cur[i] >>= 1;
  q.push(1) , cur[1] = 0;
  while (!q.empty())
  {
    x = q.front() , q.pop();
    for (i = e[x].size() - 1 ; i >= 0 ; -- i)
    {
      y = e[x][i].x , z = e[x][i].f;
      if (cur[y])
      {
        cur[y] -= z;
        d[e[x][i].p] = !e[x][i].d;
        if (!cur[y] && y != n)
          q.push(y);
      }
    }
  }
  for (i = 1 ; i <= m ;i ++)
    printf("%d\n",d[i]);
}

int main()
{
  work();
  return 0;
}