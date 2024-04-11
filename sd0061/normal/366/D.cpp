#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 2005
using namespace std;
typedef long long LL;
int n , m , d[N << 3] , D;
struct edge
{
    int x , next , l , r;
}e[N << 3];
int pre[N] , mcnt;
deque<int> q;
int val[N << 3];
int dis[N];
bool f[N];
int check(int val)
{
  int i , x , y , z , st = 1;
  for (i = 1 ; i <= n ; ++ i)
    dis[i] = 1 << 29;
  dis[st] = 0 , f[st] = 1 , q.push_back(st);
  while (!q.empty())
  {
    x = q.front() , q.pop_front() , f[x] = 0;
    for (i = pre[x] ; ~i ; i = e[i].next) if (e[i].r >= val)
    {
      y = e[i].x , z = max(dis[x] , e[i].l);
      if (dis[y] > z)
      {
        dis[y] = z;
        if (!f[y])
        {
          if (q.empty() || dis[y] < dis[q.front()])
            q.push_front(y);
          else q.push_back(y);
          f[y] = 1;
        }
      }
    }
  }
  if (dis[n] == 1 << 29) return 0;
  return val - dis[n] + 1;
}


void work()
{
    int i , j , x , y , l , r ,  ans = 0;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d%d%d",&x,&y,&l,&r);
        e[mcnt] = (edge){y , pre[x] , l , r} , pre[x] = mcnt ++;
        e[mcnt] = (edge){x , pre[y] , l , r} , pre[y] = mcnt ++;
        d[D ++] = l , d[D ++] = r;
    }
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 0 ; i < D ; ++ i)
        ans = max(check(d[i]) , ans);
    if (ans)
        cout << ans << endl;
    else
        puts("Nice work, Dima!");
}


int main()
{
   // freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}