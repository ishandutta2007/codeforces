#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 505
typedef long long LL;
using namespace std;
int n ;
int del[N], g[N][N], d[N][N];
bool f1[N] , f2[N];
LL ans[N];
int a[N] , cnt;

void dijkstra(int s)
{
  int i , j , x , y;
  memset(f1 , 0 , sizeof(f1));
  memset(f2 , 0 , sizeof(f2));
  for (i = 1 ; i <= cnt ; ++ i)
    d[a[i]][s] = g[a[i]][s] , d[s][a[i]] = g[s][a[i]];

  for (j = 1 ; j <= cnt ; ++ j)
  {
    x = -1;
    for (i = 1 ; i <= cnt ; ++ i)
      if (!f1[i] && (x == -1 || d[s][a[i]] < d[s][a[x]]))
        x = i;
    f1[x] = 1 , x = a[x];
    for (i = 1 ; i <= cnt ; ++ i)
      if (!f1[i] && d[s][a[i]] > d[s][x] + d[x][a[i]])
        d[s][a[i]] = d[s][x] + d[x][a[i]];

    x = -1;
    for (i = 1 ; i <= cnt ; ++ i)
      if (!f2[i] && (x == -1 || d[a[i]][s] < d[a[x]][s]))
        x = i;
    f2[x] = 1 , x = a[x];
    for (i = 1 ; i <= cnt ; ++ i)
      if (!f2[i] && d[a[i]][s] > d[x][s] + d[a[i]][x])
        d[a[i]][s] = d[x][s] + d[a[i]][x];
  }
}

int work()
{
  int i , j , k , x , y;
  LL sum;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= n ; ++ j)
      scanf("%d",&g[i][j]);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&del[i]);
  a[cnt = 1] = del[n];
  for (k = n - 1 ; k > 0 ; -- k)
  {
    a[++ cnt] = x = del[k];
    dijkstra(x);
    sum = 0;

    for (i = 1 ; i <= cnt ; ++ i)
      for (j = 1 ; j <= cnt ; ++ j) if (i != j)
        d[a[i]][a[j]] = min(d[a[i]][a[j]] , d[a[i]][x] + d[x][a[j]]) , sum += d[a[i]][a[j]];
    ans[k] = sum;
  }
  ans[n] = 0;
  for (i = 1 ; i <= n; ++ i)
    printf("%I64d " , ans[i]);
}

int main()
{
  //int _;cin>>_;while(_--)
  //while (~scanf("%d%d%d",&n,&m,&Q))
    work();
  //printf("%d" ,kase );
  return 0;
}