#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100005
#define inf (1 << 30)
int n,m,p[N],cnt,t[N];
int ps[N],q[50*N],d[N];
bool f[N];
struct temp
{
  int l ,r;     
}star[N << 1];
struct edge
{
  int x,w,next;     
}e[N << 1];

int caltime(int x,int t)
{
  int top = ps[x],bot = ps[x + 1] - 1,mid;
  while (top <= bot)
  {
    mid = (top + bot) >> 1;
    if (star[mid].r < t)
      top = mid + 1;
    else if (star[mid].l > t)
      bot = mid - 1;
    else return t;      
  }
  //printf("%d %d -> [%d,%d]\n",x,t,star[mid].l,star[mid].r);
  if (t > star[mid].r && (t < star[mid + 1].l || mid + 1 == ps[x + 1]))
    return star[mid + 1].l;
  if (t < star[mid].l && (t > star[mid - 1].r || mid - 1 == ps[x] - 1))
    return star[mid].l;
}

int main()
{
  int i ,j, x , y, z ,top ,bot;
  scanf("%d %d",&n,&m);  
  while (m --)
  {
    scanf("%d %d %d",&x,&y,&z);
    e[++ cnt].x = y, e[cnt].w = z ,e[cnt].next = p[x] , p[x] = cnt;
    e[++ cnt].x = x, e[cnt].w = z ,e[cnt].next = p[y] , p[y] = cnt;         
  }
  y = 0;
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%d",&x);
    ps[i] = ++ y;
    star[y].l = - 1;
    for (j = 1 ;j <= x ;j ++)
      scanf("%d",&t[j]);
    for (j = 1 ;j <= x ;j ++)
      if (t[j] == star[y].l)
      {
        star[y].l = t[j] + 1;       
      }
      else if (t[j] > star[y].l)
      {
        star[y].r = t[j] - 1; 
        y ++;
        star[y].l = t[j] + 1;   
      } 
    star[y].r = 1 << 30;  
  }
  ps[n + 1] = y;
  for (i = 1 ;i <= n ;i ++)
    d[i] = inf;
  d[1] = caltime(1,0) , f[1] = 1, q[0] = 1, top = bot = 0;
  while (top <= bot)
  {
    x = q[top ++];
    for (i = p[x]; i;i = e[i].next)
    {
      y = e[i].x ;
      if (y != n) 
        z = caltime(y,d[x] + e[i].w);
      else z = d[x] + e[i].w;
      if (d[y] > z)
      {
        d[y] = z;
        if (!f[y])
        {
          d[y] = z;
          f[y] = 1;
          q[++ bot] = y;        
        }       
      }  
    }    
    f[x] = 0; 
  }  
  if (d[n] >= inf)
    d[n] = -1;
  printf("%d",d[n]);
  return 0;
}