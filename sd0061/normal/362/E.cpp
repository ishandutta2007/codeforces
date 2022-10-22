#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define N 55
#define M 200005
typedef long long LL;
int s, t , ans , maxflow;
int pre[N] , mcnt;
struct arc
{
  int x , f , c , next;
}e[M];

void addarc(int x ,int y ,int z ,int c)
{
  e[mcnt] = (arc){y , z , c , pre[x]} , pre[x] = mcnt ++;
  e[mcnt] = (arc){x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
  // printf("%d %d %d %d\n",x,y,z,c);
}

int d[N] , p[N];
bool f[N];
deque<int> q;

bool Bellman_Ford()
{
  int i , x , y , z;
  memset(f , 0 , sizeof(f));
  for (i = 1; i <= t ; ++ i) d[i] = 1 << 30;
  d[s] = 0 , f[s] = 1 , q.push_back(s);
  while (!q.empty())
  {
    x = q.front() , q.pop_front() , f[x] = 0;
    for (i = pre[x] ; ~i ; i = e[i].next)
    {
      y = e[i].x , z = e[i].c;
      if (e[i].f && d[y] > d[x] + z)
      {
        d[y] = d[x] + z , p[y] = i;
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
  return d[t] != 1 << 30;
}

int n , k ;
int Mincostflow()
{
  maxflow = 0 , ans = 0;
  int x;
  while (Bellman_Ford())
  {
    int flow = 1 << 30;
    for (x = t ; x != s ; x = e[p[x] ^ 1].x)
      flow = min(flow , e[p[x]].f);
    if (k < d[t]) break;
    flow = min(flow , d[t] ? k / d[t] : 1 << 30);
    k -= d[t] * flow;
    maxflow += flow , ans += d[t] * flow;
    for (x = t ; x != s ; x = e[p[x] ^ 1].x)
      e[p[x]].f -= flow , e[p[x] ^ 1].f += flow;
  }
  return maxflow;
}
void work()
{
    int i , j , x;
    memset(pre , -1 , sizeof(pre));
    scanf("%d%d",&n,&k);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
        {
            scanf("%d",&x);
            if (!x) continue;
            addarc(i , j , x , 0);
            addarc(i , j , 1 << 30 , 1);
        }
    s = 1 , t = n;
    cout << Mincostflow() << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}