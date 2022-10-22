#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>
#define fi first
#define se second
#define N 5005
using namespace std;
int n , K , s, t , ans , maxflow;
struct arc
{
  int x , f ;double c ;int re;
};
vector<arc> e[N];

void addarc(int x ,int y ,int z ,double c)
{
  e[x].push_back((arc) {y ,z ,c ,e[y].size()});
  e[y].push_back((arc) {x ,0 ,-c ,e[x].size() - 1});
 // printf("%d %d %d %d\n",x,y,z,c);
}

pair<int , int> p[N];
double d[N];
bool f[N];
deque<int> q;
pair<int ,int> a[N];
bool cmp(pair<int ,int> x, pair<int ,int> y)
{
  if (x.se == y.se)
    return x.fi < y.fi;
  return x.se > y.se;
}
double dis(pair<int ,int> x, pair<int ,int> y)
{
  return sqrt((double)(x.fi - y.fi)*(x.fi - y.fi) + (x.se - y.se)*(x.se - y.se));
}
bool Bellman_Ford()
{
  int i , x , y ; double z;
  memset(f,0,sizeof(f));
  for (i = 0; i <= t ; ++ i) d[i] = 1 << 29;
  d[s] = 0 , f[s] = 1 ;
  q.push_back(s);
  while (!q.empty())
  {
    x = q.front() , q.pop_front() , f[x] = 0;
    for (i = e[x].size() - 1 ;i >= 0 ;-- i)
    {
      y = e[x][i].x , z = e[x][i].c;
      if (e[x][i].f && d[y] > d[x] + z)
      {
        d[y] = d[x] + z , p[y] = make_pair(x,i);
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
  return d[t] != 1 << 29;
}


void Mincostflow()
{
  maxflow = 0 ; double ans = 0;
  int x;
  while (Bellman_Ford())
  {
    int flow = 1 << 30;
    for (x = t ; x != s ; x = p[x].first)
      flow = min(flow ,e[p[x].first][p[x].second].f);
    maxflow += flow , ans += d[t] * flow;
    for (x = t ; x != s ; x = p[x].first)
      e[p[x].first][p[x].second].f -= flow ,
      e[x][e[p[x].first][p[x].second].re].f += flow;
  }
  if (maxflow + 1 < n)
    printf("-1");
  else printf("%.15lf",ans);
}


void work()
{
  int i , j;
  scanf("%d",&n);
  s = n + n , t = s + 1;
  for (i = 0 ; i < n ;i ++)
    scanf("%d%d",&a[i].fi , &a[i].se);
  sort(a , a + n , cmp);
  for (i = 0 ;i < n ;i ++)
    for (j = i + 1 ; j < n;j ++)
      if (a[i].se > a[j].se)
        addarc(i , j + n , 1 , dis(a[i] , a[j]));
  for (i = 0 ;i < n ;i ++)
    addarc(s , i , 2 , 0) , addarc(i + n , t , 1 , 0);
  Mincostflow();
}

int main()
{
  work();
  return 0;
}