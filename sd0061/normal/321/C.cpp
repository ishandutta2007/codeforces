#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
#define sqr(x) ((long long)(x)*(x))
int n , pre[N] , mcnt;
struct edge
{
  int x , next;
}e[N << 1];
int ans[N];

int q[N] , bot , top , d[N] , p[N];
bool f[N];
int BFS(int x)
{
  int i  , y;
  q[top = bot = 0] = x , f[x] = d[x] = 1 , p[x] = 0;
  while (top <= bot)
  {
    x = q[top ++];
    for (i = pre[x] ; ~i ; i = e[i].next) if (!ans[e[i].x] && !f[y = e[i].x])
      f[y] = 1 , d[y] = d[x] + 1 , q[++ bot] = y , p[y] = x;
  }
  x = -1;
  for (i = 0 ; i <= bot ; ++ i)
  {
    f[q[i]] = 0;
    if (~x || d[q[i]] > d[x])
      x = q[i];
  }
  return x;
}

void work(int x , int rank)
{
  int i , y , z , j;
  y = BFS(x);
  z = BFS(y) , j = d[z] / 2;
  while (j --) z = p[z];
  ans[z] = 'A' + rank;
  for (i = pre[z] ; ~i ; i = e[i].next) if (!ans[y = e[i].x])
    work(y , rank + 1);
}

int main()
{
   int i , x , y;
   scanf("%d",&n);
   memset(pre , -1 , sizeof(pre));
   for (i = 1 ; i < n ; ++ i)
   {
     scanf("%d%d",&x,&y);
     e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
     e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
   }
   work(1 , 0);
   for (i = 1 ; i <= n ; ++ i)
     printf("%c " , ans[i]);
   return 0;
}