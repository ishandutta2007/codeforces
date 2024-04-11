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
#define N 1005
#define LL long long
int n , m , s , t ;
LL dis[N];
bool f[N];
struct edge
{
  int x , w;
};
vector<edge> g1[N] , g2[N];
deque<int> q;
void Bellman_Ford(vector<edge>* e , LL* d, int st)
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
        d[y] = d[x] + z;
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

void work()
{
  int i , j , x , y , z;
  cin >> n >> m >> s >> t;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d%d",&x,&y,&z);
    g1[x].pb((edge){y , z});
    g1[y].pb((edge){x , z});
  }
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%d%d",&y,&z);
    Bellman_Ford(g1 , dis , i);
    for (j = 1 ; j <= n ; ++ j)
      if (dis[j] <= y)
        g2[i].pb((edge){j , z});
  }
  Bellman_Ford(g2 , dis , s);
  if (dis[t] == 1LL << 60)
    dis[t] = -1;
  cout << dis[t] << endl;
}


int main()
{
    work();
  return 0;
}