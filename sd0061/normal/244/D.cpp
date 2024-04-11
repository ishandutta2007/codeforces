#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , m , t , h , d[N];
vector<int> e[N] , vu , vv;
bool f[N];

int main()
{
  int i ,j , x , y , u , v;
  cin >> n >> m >> h >> t;
  while (m --)
  {
    scanf("%d%d",&x,&y);
    ++ d[x] , ++ d[y];
    e[x].push_back(y);
    e[y].push_back(x);     
  }
  for (u = 1 ; u <= n ; u ++)
    if (d[u] > h )
      for (j = 0 ; j < d[u]; ++ j)
        if ((v = e[u][j]) && d[v] > t)
        { 
          x = 0;
          for (i = 0 ; i < d[v] ; ++ i)
            if (u != e[v][i])
              f[e[v][i]] = 1;
          for (i = 0 ; i < d[u] ; ++ i)
            if (f[e[u][i]] && e[u][i] != v)
              x ++;
          if (d[u] + d[v] - 2 - x >= h + t)
          {
            printf("YES\n%d %d\n",u,v);       
            y = 0;       
            for (i = 0 ; i < d[u] && y < h; ++ i)
              if (!f[e[u][i]] && e[u][i] != v)
                printf("%d ",e[u][i]) , ++ y;
            for (i = 0 ; i < d[u] && y < h; ++ i)
              if (f[e[u][i]] && e[u][i] != v)
                printf("%d ",e[u][i]) , ++ y , f[e[u][i]] = 0;
            printf("\n");   
            y = 0;        
            for (i = 0 ; i < d[v] && y < t; ++ i)
              if (f[e[v][i]] && e[v][i] != u)
                printf("%d ",e[v][i]) , ++ y , f[e[v][i]] = 0;
            return 0;    
          }         
          for (i = 0 ; i < d[v] ; ++ i)
            f[e[v][i]] = 0;
        }
  printf("NO");        
  return 0;
}