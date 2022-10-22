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
#define N 1001
int n , m , d[N] , d2[N] , D , a[N];
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
  for (i = 1 ; i <= n + n; ++ i)
    d[i] = 1 << 30 , f[i] = 0;
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

void add(int x , int y ,int z)
{
  e[x].pb((edge){y , z});
 // printf("%d %d %d\n" , x , y , z);
}
int xx[N] , yy[N];
void work()
{
  int i , j , x , y , z , ans = 0;
  scanf("%d%d",&n,&D);
  for (i = 2 ; i < n ; ++ i)
    scanf("%d",&a[i]) , add(i , i + n , -a[i]);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d%d",&xx[i] , &yy[i]);
  for (i = 1 ; i <= n ;i ++)
    for (j = 1 ; j <= n ;j ++) if (i != j)
      add(i + n , j , D * (abs(xx[i] - xx[j]) + abs(yy[i] - yy[j])));
  Bellman_Ford(1 + n);
  printf("%d\n", d[n]);
}

int main()
{
    work();
  return 0;
}