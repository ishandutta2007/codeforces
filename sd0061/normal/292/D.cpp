#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 505
#define fi first
#define se second
int n , m , k , p[N];
pair<int ,int> e[10005];
int f1[10005][505] , s1[10005];
int f2[10005][505] , s2[10005];


int getf(int* f , int x) {return x == f[x] ? x : f[x] = getf(f , f[x]);}


void work()
{
  int i , x , y , j;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d%d",&e[i].fi , &e[i].se);

  for (i = 1 ; i <= n ; ++ i)
    f1[0][i] = f2[m + 1][i] = i;
  s1[0] = s2[n + 1] = n;
  for (i = 1 ; i <= m ; ++ i)
  {
    for (j = 1 ; j <= n ; ++ j)
      f1[i][j] = f1[i - 1][j];
    s1[i] = s1[i - 1];
    if (getf(f1[i] , e[i].fi) != getf(f1[i] ,e[i].se))
      f1[i][getf(f1[i] ,e[i].fi)] = getf(f1[i] ,e[i].se) , -- s1[i];
  }
  for (i = m ; i > 0 ; -- i)
  {
    for (j = 1 ; j <= n ; ++ j)
      f2[i][j] = f2[i + 1][j];
    s2[i] = s2[i + 1];
    if (getf(f2[i] ,e[i].fi) != getf(f2[i] ,e[i].se))
      f2[i][getf(f2[i] ,e[i].fi)] = getf(f2[i] , e[i].se) , -- s2[i];
  }
  scanf("%d",&k);
  while (k --)
  {
    int l , r;
    scanf("%d%d",&l,&r) , -- l , ++ r;
    for (i = 1 ; i <= n ; ++ i)
      p[i] = i;
    int ans = n;
    for (i = 1 ; i <= n ; ++ i)
    {
      x = getf(p , getf(f1[l] , i ));
      if (getf(p , i) != x)
        p[getf(p , i)] = x , -- ans;
      x = getf(p , getf(f2[r] , i ));
      if (getf(p , i) != x)
        p[getf(p , i)] = x , -- ans;
    }
    printf("%d\n" , ans);
  }
}

int main()
{
    work();
  return 0;
}